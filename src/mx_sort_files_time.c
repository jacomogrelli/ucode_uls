#include "uls.h"

static void ascii_swap(t_lstat *i, t_lstat *j, int *flags) {
    if (!flags[mx_get_char_index(FLAGS, 'r')])
        if (mx_strcmp(i->name, j->name) > 0)
                    mx_data_swap(i, j);
     if (flags[mx_get_char_index(FLAGS, 'r')])
        if (mx_strcmp(i->name, j->name) < 0)
                    mx_data_swap(i, j);
}

void mx_sort_files_time(t_lstat *files, int *flags) {
    int r = flags[mx_get_char_index(FLAGS, 'r')];

    for (t_lstat *i = files; i->next; i = i->next) {
        for (t_lstat *j = i->next; j; j = j->next) {
            if (r) {
                if (i->st_time > j->st_time)
                    mx_data_swap(i, j);
                if (i->st_time == j->st_time) {
                    if (i->st_time_nsec > j->st_time_nsec)
                        mx_data_swap(i, j);
                    else
                        ascii_swap(i, j, flags);
                }
            }
            if (!r) {
                if (i->st_time < j->st_time)
                    mx_data_swap(i, j);
                if (i->st_time == j->st_time)
                    ascii_swap(i, j, flags);
            }
        }
    }
}
