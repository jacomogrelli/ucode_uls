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
    mx_output_error(all->E);
    mx_output_files(all->F, flags);
    mx_get_dirlist(all, flags);
    mx_output_folders(all->D, flags);
    // if (flag_count > 0) //временная, убрать при первом использовании
    // if (argc > flag_count)
    //     mx_basic(argc, argv, flag_count);
    // system("leaks -q uls");
}
