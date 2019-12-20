#include "uls.h"

/* все реализуемые флаги добавлять в FLAGS в uls.h */

/*
* ВНУТРЕННИЙ АУДИТОР ЮЛС
* 1. Все статики называть uls_
*/

int main (int argc, char **argv) {
    int flag_count = mx_flag_check(argc, argv);

    mx_empty_flag(argc, flag_count, argv);
    // printf("flag count = %d\n", flag_count);
}
