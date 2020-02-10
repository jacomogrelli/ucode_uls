#include "uls.h"

void mx_1_out(t_lstat *F) {
    for (; F != NULL; F = F->next ) {
        mx_printstr(F->path);
        mx_printstr("\n");
    }
}
