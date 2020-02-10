#include "uls.h"

static t_list *get_a(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_list *head = D;
    char *name = NULL;

    for (; D; D = D->next) {
        if ((dirp = opendir(D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if (mx_strcmp(buf->d_name, ".") != 0 &&
                    mx_strncmp(buf->d_name, "..", 2) != 0)
                    if (lstat(name = mx_namejoin(D->data, buf->d_name),
                        &buf2) >= 0) {
                        mx_strdel(&name);
                        if (MX_ISDIR(buf2.st_mode)) {
                            mx_push_back(&D, name = mx_namejoin(D->data,
                                         buf->d_name));
                            mx_strdel(&name);
                        }
                    }
            }
            if (closedir(dirp) < 0)
                exit(1);
        }
    }
    D = head;
    return D;
}

static t_list *get_default(t_list *D) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;
    t_list *head = D;
    char *name = NULL;

    for (; D != NULL; D = D->next) {
        if ((dirp = opendir(D->data))) {
            while ((buf = readdir(dirp)) != NULL) {
                if (buf->d_name[0] != '.')
                    if (lstat(name = mx_namejoin(D->data, buf->d_name),
                        &buf2) >= 0) {
                        mx_strdel(&name);
                        if (MX_ISDIR(buf2.st_mode)) {
                            mx_push_back(&D, name = mx_namejoin(D->data,
                                         buf->d_name));
                            mx_strdel(&name);
                        }
                    }
            }
            if (closedir(dirp) < 0)
                exit(1);
        }
    }
    D = head;
    return D;
}

t_list *mx_R(t_list *D, int *flags) {
    if (!D)
        return D;
    if (flags[mx_get_char_index(FLAGS, 'A')])
        D = get_a(D);
    else
        D = get_default(D);
    return D;
}
