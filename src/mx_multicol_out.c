#include "uls.h"

static int get_maxlen(t_lstat *F) {
    int max_len = 0;

    for (; F != NULL; F = F->next)
        if (mx_strlen(F->name) > max_len)
            max_len = mx_strlen(F->name);
    return max_len;
}
static int get_max_spaces(int max) {
    int tmp;
    int spaces;

    tmp = max - 8;
    if (tmp < 0) {
        spaces = 8 - max;
        return spaces;
    }
    while (tmp >= 8)
        tmp -= 8;
    spaces = 8 - tmp;
    return spaces;
}

static int count_lines(int num_f, int max) {
    int win_col = mx_get_winsize();
    int count = 1;
    int space = get_max_spaces(max);
    int c_words;
    int add;

    if (num_f * (max + space) >= win_col) {
        c_words = win_col / (max + space);
        if (c_words == 0)
            c_words++;
        add = 0;
        if ((num_f % c_words) != 0)
            add++;
        count = (num_f / c_words) + add;
    }
    if (!num_f)
        count = 0;
    return count;
}

void mx_multicol_out(t_lstat *F) {
    int num_f = mx_get_num_files(F);
    int max = get_maxlen(F);
    int count = count_lines(num_f, max);

    for (int i = 0; i < count; i++)
        for (int j = 0; j < num_f; j++)
            if (j == i || (j - i) % count == 0) {
                mx_printstr(mx_struct_index(F, j));
                if (j + count >= num_f)
                    mx_printstr("\n");
                else
                    mx_def_space(F, max, j);
            }

}
