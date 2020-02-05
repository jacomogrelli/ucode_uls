#include "uls.h"

void default_l(t_lstat *o);
void arg_l(t_lstat *o, int *flags);

void mx_output_files(t_lstat *out, int *flags) {
    if (!flags) return; //временная ХУЙНЯ убрать
// mx_ascii_sort_list(out);
    if (flags[mx_get_char_index(FLAGS, 'a')])
        mx_default_l(out);
    // if (flags[mx_get_char_index(FLAGS, 'l')])
    //     arg_l(out, flags);
    // while (out) {
    //     mx_printstr(" ");
    //     mx_printstr(out->name);
    //     out = out->next;

    // }
}

// void arg_l(t_lstat *o, int *flags) {
//     struct stat buf;
//     struct stat *fill = NULL;

//     if (!o)
//         exit(1);
//     lstat(o->path, &buf);
//     if (mx_lstat_fill(*fill, o->path, flags) != 0)
//         mx_default_l(o);
//     printf("HELOL");
// }
