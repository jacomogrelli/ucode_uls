#include "uls.h"

static t_list *get_A(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;

    for (t_list *p = D; p; p = p->next) {
        if (!(dirp = opendir(p->data)))
            exit(1);
        while ((buf = readdir(dirp)) != NULL)
            if (mx_strcmp(buf->d_name, ".") != 0
                && mx_strcmp(buf->d_name, "..") != 0)
                if (lstat(mx_namejoin(p->data, buf->d_name), &buf2) >= 0)
                    if (MX_ISDIR(buf2.st_mode))
                        mx_push_back(&p, mx_namejoin(p->data, buf->d_name));
        if (closedir(dirp) < 0)
            exit(1);
    }
    return D;
}

static t_list *get_default(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;

    for (t_list *p = D; p != NULL; p = p->next) {
        if (!(dirp = opendir(p->data)))
            exit(1);
        while ((buf = readdir(dirp)) != NULL)
            if (buf->d_name[0] != '.')
                if (lstat(mx_namejoin(p->data, buf->d_name), &buf2) >= 0)
                    if (MX_ISDIR(buf2.st_mode))
                        mx_push_back(&p, mx_namejoin(p->data, buf->d_name));
        if (closedir(dirp) < 0)
            exit(1);
    }
    return D;
}

void mx_R(t_list *D, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'A')])
        D = get_A(D);
    else
        D = get_default(D);
    mx_ascii_sort_list(D);
    mx_printlist(D);
}
