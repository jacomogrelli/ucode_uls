#include "uls.h"

static void get_a_help(DIR *dir, t_uls_out *p, t_uls_out *all, int *flags) {
    struct dirent *bf;
    struct stat bf2;
    char *tmp = NULL;

    while ((bf = readdir(dir)) != NULL) {
        if (mx_strcmp(bf->d_name, ".") != 0 &&
            mx_strncmp(bf->d_name, "..", 2) != 0)
            if (lstat(tmp = mx_namejoin(p->D->data, bf->d_name), &bf2) >= 0) {
                mx_strdel(&tmp);
                mx_push_stat(&all->Dlist, mx_lstat_fill(bf2,
                tmp = mx_namejoin(p->D->data, bf->d_name), flags, true));
                mx_strdel(&tmp);
            }
    }
}

static t_uls_out *get_a(t_uls_out *all, int *flags) {
    DIR *dirp;
    t_uls_out *ptr = all;
    t_list *head = all->D;

    for (;ptr->D; ptr->D = ptr->D->next) {
        if ((dirp = opendir(ptr->D->data))) {
            get_a_help(dirp, ptr, all, flags);
            closedir(dirp);
        }
        all = mx_t_uls_out_init(all);
    }
    all = ptr;
    all->D = head;
    return all;
}

static void get_default_help(DIR *dir, t_uls_out *a, t_uls_out *p, int *fl) {
    struct dirent *bf;
    struct stat bf2;
    char *tmp = NULL;

    while ((bf = readdir(dir)) != NULL) {
                if(bf->d_name[0] != '.')
                    if (lstat(tmp = mx_namejoin(p->D->data, bf->d_name),
                        &bf2) >= 0) {
                        mx_strdel(&tmp);
                        mx_push_stat(&a->Dlist,
                        mx_lstat_fill(bf2, tmp = mx_namejoin(p->D->data,
                        bf->d_name), fl, true));
                        mx_strdel(&tmp);
                    }
            }
}

static t_uls_out *get_default(t_uls_out *all, int *flags) {
    DIR *dirp;
    t_uls_out *ptr = all;
    t_list *head = all->D;

    for (;ptr->D; ptr->D = ptr->D->next) {
        if ((dirp = opendir(ptr->D->data))) {
            get_default_help(dirp, all, ptr, flags);
            closedir(dirp);
        }
        all = mx_t_uls_out_init(all);
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
