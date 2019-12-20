#include "uls.h"

/*
* функция принимает argc, argv, проверяет, входят ли флаги в множество
* константы FLAGS и возвращает количество принимаемых аргументов, которые
* являются наборами флагов или прерыванием флагов, для того, что бы начать
считывать аргументы сразу после них. Дальше использовать аргумент argv[res]
*/

static void uls_err_illegal_option(char c);

int mx_flag_check(int argc, char **argv) {
    int res = 1;

    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (mx_strcmp(argv[i], "--") == 0)
            return res + 1;
        if (argv[i][0] == '-') {
            res++;
            for (int j = 1; argv[i][j]; j++) {
                if (mx_get_char_index(FLAGS, (argv[i][j])) == -1)
                    uls_err_illegal_option(argv[i][j]);
            }
        }
    }
    return res;
}

static void uls_err_illegal_option(char c) {
    mx_printerr("uls: illegal option -- ");
    write(2, &c, 1);
    mx_printerr("\nusage: ls [-");
    mx_printerr(FLAGS);
    mx_printerr("] [file ...]\n");
    exit (1);
}
