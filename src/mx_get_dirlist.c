#include "uls.h"

static t_uls_out *get_a(t_uls_out *all, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_uls_out *ptr = all;
    t_list *head = all->D;
    char *name = NULL;

    for (;ptr->D; ptr->D = ptr->D->next) {
        if ((dirp = opendir(ptr->D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if (mx_strcmp(buf->d_name, ".") != 0 &&
                    mx_strncmp(buf->d_name, "..", 2) != 0)
                        if (lstat(name = mx_namejoin(ptr->D->data, buf->d_name),
                            &buf2) >= 0) {
                            mx_strdel(&name);
                            mx_push_stat(&all->Dlist, mx_lstat_fill(buf2,
                            name = mx_namejoin(ptr->D->data, buf->d_name),
                            flags, true));
                            mx_strdel(&name);
                        }
            }
            if (closedir(dirp) < 0)
                exit(1);
            all = mx_t_uls_out_init(all);
        }
    }
    all = ptr;
    all->D = head;
    return all;
}

static t_uls_out *get_default(t_uls_out *all, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_uls_out *ptr = all;
    t_list *head = all->D;
    char *name = NULL;

    for (;ptr->D; ptr->D = ptr->D->next) {
        if ((dirp = opendir(ptr->D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if(buf->d_name[0] != '.')
                    if (lstat(name = mx_namejoin(ptr->D->data, buf->d_name),
                        &buf2) >= 0) {
                        mx_strdel(&name);
                        mx_push_stat(&all->Dlist, mx_lstat_fill(buf2, name =
                        mx_namejoin(ptr->D->data, buf->d_name), flags, true));
                        mx_strdel(&name);
                    }
            }
            if (closedir(dirp) < 0)
                exit(1);
            all = mx_t_uls_out_init(all);
        }
    }
    all = ptr;
    all->D = head;
    return all;
}

t_uls_out *mx_get_dirlist(t_uls_out *all, int *flags) {
    if (!all->D)
        return all;
    if (flags[mx_get_char_index(FLAGS, 'A')])
        all = get_a(all, flags);
    else
        all = get_default(all, flags);
    return all;
}
