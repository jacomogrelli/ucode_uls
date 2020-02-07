#include "uls.h"

static t_uls_out *get_a(t_uls_out *all, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;

    for (;all->D; all->D = all->D->next) {
        if ((dirp = opendir(all->D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if (mx_strcmp(buf->d_name, ".") != 0 &&
                    mx_strncmp(buf->d_name, "..", 2) != 0)
                        if (lstat(mx_namejoin(all->D->data, buf->d_name),
                            &buf2) >= 0)
                            mx_push_stat(&all->Dlist, mx_lstat_fill(buf2,
                            mx_namejoin(all->D->data, buf->d_name),
                            flags, true));
            }
            if (closedir(dirp) < 0)
                exit(1);
        }
    }
    return all;
}

static t_uls_out *get_default(t_uls_out *all, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;

    for (;all->D; all->D = all->D->next) {
        if ((dirp = opendir(all->D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if (buf->d_name[0] != '.')
                    if (lstat(mx_namejoin(all->D->data, buf->d_name),
                        &buf2) >= 0)
                        mx_push_stat(&all->Dlist, mx_lstat_fill(buf2,
                        mx_namejoin(all->D->data, buf->d_name), flags, true));
            }
            if (closedir(dirp) < 0)
                exit(1);
        }
    }
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
