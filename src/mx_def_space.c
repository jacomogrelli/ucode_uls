#include "uls.h"

void mx_def_space(t_lstat *F, int max, int j) {
    int cur_len = mx_strlen(mx_struct_index(F, j));
    int add = 8;

    if (cur_len < 8) {
        mx_printstr("\t");
        cur_len = 8;
    }
    while (cur_len <= max) {
        mx_printstr("\t");
        while (add <= cur_len)
            add += 8;
        cur_len = add;
    }
}
