#include "uls.h"

void mx_output_files(t_lstat *out, int *flags) {
    if (!flags) return; //временная ХУЙНЯ убрать
// mx_ascii_sort_list(out->files);
    while(out) {
        printf("%s  ", out->name);
        out = out->next;
    }
}
