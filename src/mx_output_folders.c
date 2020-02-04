#include "uls.h"

void mx_output_folders(t_list *out, int *flags) {
    if (flags[mx_get_char_index(FLAGS, 'l')])
        mx_print_l(out, flags);
    if (flags[mx_get_char_index(FLAGS, 'F')])
        flag_F(out);
//     else {
//         for (;out; out = out->next) {
//             mx_printstr(out->data);
//             mx_printstr(" ");
//             mx_printstr("\n");
//         }
//     }
    free(out);
}
