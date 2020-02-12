#include "uls.h"

void mx_sort_dirs(t_list *dirs, int *flags) {
    if (!dirs)
        return;
    if (flags[mx_get_char_index(FLAGS, 'S')]) {
        mx_sort_dirs_size(dirs, flags);
        return;
    }
    if (flags[mx_get_char_index(FLAGS, 't')] &&
        !flags[mx_get_char_index(FLAGS, 'u')]) {
        mx_sort_dirs_time(dirs, flags);
        return;
    }
    if (flags[mx_get_char_index(FLAGS, 't')] &&
        flags[mx_get_char_index(FLAGS, 'u')]) {
        mx_sort_dirs_utime(dirs, flags);
        return;
    }
    else
        mx_sort_dirs_ascii(dirs, flags);
    return;
}
