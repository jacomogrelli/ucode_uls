#include "uls.h"

void mx_sort_files(t_lstat *files, int *flags) {
    if (!files)
        return;
    if (flags[mx_get_char_index(FLAGS, 'S')]) {
        mx_sort_files_size(files, flags);
        return;
    }
    if (flags[mx_get_char_index(FLAGS, 't')] &&
        !flags[mx_get_char_index(FLAGS, 'u')]) {
        mx_sort_files_time(files, flags);
        return;
    }
    else
        mx_sort_files_ascii(files, flags);
    return;
}
