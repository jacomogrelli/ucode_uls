#include "uls.h"

t_lstat *odir(t_list *D, int *flags);
void print_arg_lstat(t_lstat *D);
// void print_arg_lstat(t_list *D, int *flags);

void mx_output_folders(t_list *out, int *flags) {
    t_lstat *res = odir(out, flags);

    if (flags[mx_get_char_index(FLAGS, 'l')])
        print_arg_lstat(res);
    else {
        for (;out; out = out->next) {
            mx_printstr(out->data);
            mx_printstr(" ");
            mx_printstr("\n");
        }
    }
    mx_free_t_lstat(res);
    free(res);
}


t_lstat *odir(t_list *D, int *flags) {
    DIR *dirp;
    struct dirent *dbuf;
    struct stat buf;
    t_lstat *p = NULL;

    if (!D)
        return NULL;
    if (!(dirp = opendir(D->data)))
        exit(1);
    for (; (dbuf = readdir(dirp));) {
        lstat(dbuf->d_name, &buf);
        if (dbuf->d_name[0] != '.' && !flags[mx_get_char_index(FLAGS, 'A')])
            mx_push_stat(&p, mx_lstat_fill(buf, dbuf->d_name, flags));
        if (mx_strcmp(dbuf->d_name, ".") != 0 &&
            mx_strcmp(dbuf->d_name, "..") != 0 &&
            flags[mx_get_char_index(FLAGS, 'A')])
            mx_push_stat(&p, mx_lstat_fill(buf, dbuf->d_name, flags)); //  mx_lstat_fill - > ликов много оставляет
    }
    if (closedir(dirp) < 0)
        exit(1);
    return p;
} // 18 strok

// void print_arg_lstat(t_list *D, int *flags) {
void print_arg_lstat(t_lstat *D) {

    mx_asort_lstat(D);
    mx_default_l(D);
    // system("leaks -q uls");
}
