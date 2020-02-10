#include "uls.h"

int mx_get_num_files(t_lstat *F) {
    int sum_files = 0;

    for (; F != NULL; F = F->next)
        sum_files++;
    return sum_files;
}
