#include "uls.h"

void mx_output_files(t_lstat *F, int *flags) {
    if (F) {
        if (!flags[mx_get_char_index(FLAGS, 'l')] &&
            !flags[mx_get_char_index(FLAGS, 'o')]) {
            if (!isatty(1))
                mx_cat_out(F);
            else if (flags[mx_get_char_index(FLAGS, '1')])
                mx_1_out(F);
            else
                mx_multicol_out(F);
        }
        else
            mx_long_out(F, flags);
    }
    return;
}
