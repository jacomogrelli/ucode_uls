#include "uls.h"

void mx_output_folders(t_list *out, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'l')])
        mx_print_l(out, flags);
    // if (flags[mx_get_char_index(FLAGS, 'F')])
    //     mx_flag_F(out);
    if (flags[mx_get_char_index(FLAGS, 'R')] &&
        !flags[mx_get_char_index(FLAGS, 'd')])
            mx_R(out, flags);
    else {
        for (;out; out = out->next) {
            if (mx_strncmp(out->data, ".", 2) != 0) { // для флага -R чтобы не показывало . (DELETE!)
                mx_printstr(out->data);
                mx_printstr(" ");
                mx_printstr("\n");
            }
        }
    }
    free(out);
}
