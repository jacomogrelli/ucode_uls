#include "uls.h"

void mx_long_out(t_lstat *F, int *flags) {
    int max_size = mx_get_max_size(F);
    int max_gr = mx_get_max_group(F);

    for (; F != NULL; F = F->next) {
        mx_flong_out(F);
        mx_slong_out(F, flags, max_size, max_gr);
    }
}
