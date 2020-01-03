#include "uls.h"

/* все реализуемые флаги добавлять в FLAGS в uls.h */

/*
* ВНУТРЕННИЙ АУДИТОР ЮЛС
* 1. Все статики называть uls_
*/

int main (int argc, char **argv) {
    int *flags = NULL;
    int flag_count = mx_flag_check(argc, argv, &flags);
    if (flag_count > 0) //временная, убрать при первом использовании

    if (argc == 1 || (argc == 2 && mx_strcmp(argv[1], "--") == 0))
        mx_empty_flag();
    if (argc > flag_count)
        mx_basic(argc, argv, flag_count);
    return 0;
}
