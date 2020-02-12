#include "uls.h"

void mx_output_files(t_lstat *F, int *flags) {
    t_lstat *F1 = F;

    if (F1) {
        if (!flags[mx_get_char_index(FLAGS, 'l')] &&
            !flags[mx_get_char_index(FLAGS, 'o')]) {
            if (!isatty(1) && !flags[mx_get_char_index(FLAGS, 'm')])
                mx_cat_out(F1);
            else if (flags[mx_get_char_index(FLAGS, '1')])
                mx_1_out(F1);
            else if (flags[mx_get_char_index(FLAGS, 'm')])
                mx_m_out(F);
            else
                mx_multicol_out(F1);
        }
        else
            mx_long_out(F1, flags);
    }
    return;
}
