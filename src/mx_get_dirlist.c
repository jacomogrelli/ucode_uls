#include "uls.h"

void mx_get_dirlist(t_uls_out *all, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'R')] &&
        !flags[mx_get_char_index(FLAGS, 'd')])
            printf("DIRlist");
            mx_R(all->D, flags);
}
