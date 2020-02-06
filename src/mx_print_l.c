#include "uls.h"

t_list *getfromdir(t_list *D) {
    DIR *dirp;
    struct dirent *dbuf;
    t_list *lst = NULL;

    if (!(dirp = opendir(D->data)))
        exit(1);
    for (; (dbuf = readdir(dirp));)
        mx_push_back(&lst, dbuf->d_name);
    mx_ascii_sort_list(lst);
    return lst;
}

t_lstat *odir(t_list *D, int *flags) {
    struct stat buf;
    t_lstat *p = NULL;

    if (!D)
        return NULL;
    for ( ; D != NULL; D = D->next) {
        lstat(D->data, &buf);
        if (mx_strncmp(D->data, ".", 1) != 0 &&
            !flags[mx_get_char_index(FLAGS, 'A')])
            mx_push_stat(&p, mx_lstat_fill(buf, D->data, flags, true));
        if (mx_strcmp(D->data, ".") != 0 && mx_strcmp(D->data, "..") != 0
            && flags[mx_get_char_index(FLAGS, 'A')])
            mx_push_stat(&p, mx_lstat_fill(buf, D->data, flags, true)); //  mx_lstat_fill - > ликов много оставляет
    }
    return p;
}

void mx_print_l(t_list *D, int *flags) {
    t_lstat *res = NULL;

    if (!D)
        return;
    res = odir(getfromdir(D), flags);
    mx_default_l(res);
    mx_free_t_lstat(res);
    free(res);
    // system("leaks -q uls");
}
