#include "uls.h"

void mx_output_folders(t_list *out, int *flags) {
    if (flags == NULL)
        return;
    mx_lstat_fill()
    for (;out; out = out->next) {
        mx_printstr(out->data);
        mx_printstr(" ");
        mx_printstr("\n");

    }
}

void odir(t_list *D) {
    DIR *dirp;
    struct dirent *dbuf;
    struct stat buf;

    if (!(dirp = opendir(D->data)))
        exit(1);
    while 
}
