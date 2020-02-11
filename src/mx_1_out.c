#include "uls.h"

void mx_1_out(t_lstat *F) {
    for (; F != NULL; F = F->next ) {
        mx_print_nonprint_str(F->name);
        mx_printstr("\n");
    }
}
