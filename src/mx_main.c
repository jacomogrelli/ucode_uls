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
    mx_printlist(all->D);
    // mx_default_l(all->F);
    return 0;
    mx_output_error(all->E);
    mx_output_files(all->F, flags);
    mx_output_folders(all->D, flags); // там внутри mx_lstat_fill - > ликов много оставляет
    free(all->F); //переделать free по всему листу, а не указателю отдельной функцией
    free(all->E);
    // system("leaks -q uls");
}
