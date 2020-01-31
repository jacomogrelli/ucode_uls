#include "uls.h"

static t_list *get_A(t_list *D);
static t_list *get_default(t_list *D);

void mx_get_dirlist(t_uls_out *all, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'R')]
        && !flags[mx_get_char_index(FLAGS, 'd')]) {
        if (flags[mx_get_char_index(FLAGS, 'A')])
            all->D = get_A(all->D);
        else
            all->D = get_default(all->D);
    }
    mx_ascii_sort_list(all->D);
}

static t_list *get_A(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_list *ptr = D;

    for (; ptr; ptr = ptr->next) {
        if (!(dirp = opendir(ptr->data)))
            exit(1);
        while ((buf = readdir(dirp)) != NULL)
            if (mx_strcmp(buf->d_name, ".") != 0
                && mx_strcmp(buf->d_name, "..") != 0)
                if (lstat(mx_namejoin(ptr->data, buf->d_name), &buf2) >= 0)
                    if (MX_ISDIR(buf2.st_mode))
                        mx_push_back(&ptr,
                        mx_namejoin(ptr->data, buf->d_name));
        if (closedir(dirp) < 0)
            exit(1);
    }
    return D;
}

static t_list *get_default(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_list *ptr = D;

    for (; ptr != NULL; ptr = ptr->next) {
        if (!(dirp = opendir(ptr->data)))
            exit(1);
        while ((buf = readdir(dirp)) != NULL)
            if (buf->d_name[0] != '.')
                if (lstat(mx_namejoin(ptr->data, buf->d_name), &buf2) >= 0)
                    if (MX_ISDIR(buf2.st_mode))
                        mx_push_back(&ptr,
                        mx_namejoin(ptr->data, buf->d_name));
        if (closedir(dirp) < 0)
            exit(1);
    }
    return D;
}
