#include "uls.h"
void odir(t_list *D, int *flags);

void mx_output_folders(t_list *out, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'l')] && out != NULL)
        odir(out, flags);
    else {
        for (;out; out = out->next) {
            mx_printstr(out->data);
            mx_printstr(" ");
            mx_printstr("\n");
        }
    }
}

void odir(t_list *D, int *flags) { // форматнуть вывод и еще проблема с аргументами
    DIR *dirp;
    struct dirent *dbuf;
    struct stat buf;
    t_lstat *p = NULL;

    if (!(dirp = opendir(D->data)))
        exit(1);
    for (; (dbuf = readdir(dirp));) {
        lstat(dbuf->d_name, &buf);
            // if (mx_strcmp(dbuf->d_name, ".") < 0) {
            if (dbuf->d_name[0] != '.') {
                // printf("NAME:%s\n", dbuf->d_name);
                p = mx_lstat_fill(buf, dbuf->d_name, flags);
                // mx_asort_lstat(p);
                mx_default_l(p);
            }
    }
    if (closedir(dirp) < 0)
        exit(1);
}
