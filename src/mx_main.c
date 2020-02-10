#include "uls.h"

/* все реализуемые флаги добавлять в FLAGS в uls.h */

/*
 * ВНУТРЕННИЙ АУДИТОР ЮЛС
 * 1. Все статики называть uls_
 */

int main (int argc, char **argv) {
    int *flags = NULL;
    int flag_count = mx_flag_check(argc, argv, &flags);
    t_uls_out *all = NULL;

    all = mx_get_args(argc, flag_count, argv, flags);
    all = mx_get_dirlist(all, flags);
    all = mx_sorty(all, flags);
    mx_output_error(all->E);
    // mx_default_l(all->Dlist);
    // return 0;
    mx_output_files(all->F, flags);
    // mx_output_folders(all->D, flags); // там внутри mx_lstat_fill - > ликов много оставляет
    mx_uls_cleaner(all);
    // system("leaks -q uls");

    return 0;
}
