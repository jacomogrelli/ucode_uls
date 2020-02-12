#include "uls.h"

void mx_sort_files_ascii(t_lstat *files, int *flags) {
    int r = flags[mx_get_char_index(FLAGS, 'r')];

    for (t_lstat *i = files; i->next; i = i->next) {
        for (t_lstat *j = i->next; j; j = j->next) {
            if (!r)
                if (mx_strcmp(i->name, j->name) > 0)
                    mx_data_swap(i, j);
            if (r)
                if (mx_strcmp(i->name, j->name) < 0)
                    mx_data_swap(i, j);
        }
    }
}
