#include "uls.h"

void mx_output_files(t_lstat *out, int *flags) {
    if (!flags) return; //временная ХУЙНЯ убрать
// mx_ascii_sort_list(out->files);
    while(out) {
        mx_printstr(out->name);
        mx_printstr(" ");
        // mx_printstr(out->path);
        // mx_printstr(" ");
        // mx_printstr(out->group);
        // mx_printstr(" ");
        // mx_printstr(out->mode);
        // mx_printstr(" ");
        // mx_printstr(out->mtime);
        // mx_printstr(" ");
        // mx_printstr(out->own_name);
        // mx_printstr(" ");
        // mx_printstr(out->plink);
        // mx_printstr(" ");
        // mx_printstr(out->size_b);
        // mx_printstr(" ");
        // mx_printint(out->nlink);
        // mx_printstr("\n");
        out = out->next;
    }
}
