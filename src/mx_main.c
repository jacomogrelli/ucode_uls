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
    // mx_printint(flags[0]);

    all = mx_get_args(argc, flag_count, argv, flags);
    mx_output_error(all->errors);
    mx_output_files(all->files, flags);
    // while(all->files) {
    //     printf("%s ", all->files->name);
    //     all->files = all->files->next;
    // }
    // if (flag_count > 0) //временная, убрать при первом использовании
    // if (argc > flag_count)
    //     mx_basic(argc, argv, flag_count);
    // system("leaks -q uls");

    return 0;
}
