#include "uls.h"

/*
 * DONE
 * функция принимает argc, argv, проверяет, входят ли флаги в множество
 * константы FLAGS и возвращает количество принимаемых аргументов, которые
 * являются наборами флагов или прерыванием флагов, для того, что бы начать
 * считывать аргументы сразу после них. Дальше использовать аргумент argv[res]
 * так же функция принимает дополнительный указатель на *int, инициализируя
 * инициализируя массив 0 по размеру макроса FLAGS, а затем заменяя 0 на 1,
 * если указанный флаг имеется в макросе FLAGS в соответсвующем елементе масс
 * ива *int
 */

static void uls_err_illegal_option(char c);
static void uls_flags_arr_init(int **flags);

int mx_flag_check(int argc, char **argv, int **flags) {
    int res = 1;

    uls_flags_arr_init(flags);
    for (int i = 1; i < argc && argv[i][0] == '-'; i++) {
        if (mx_strcmp(argv[i], "--") == 0)
            return res + 1;
        if (argv[i][0] == '-') {
            res++;
            for (int j = 1; argv[i][j]; j++) {
                if (mx_get_char_index(FLAGS, (argv[i][j])) == -1)
                    uls_err_illegal_option(argv[i][j]);
                (*flags)[mx_get_char_index(FLAGS, argv[i][j])] = 1;
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

static void uls_flags_arr_init(int **flags) {
    (*flags) = malloc(sizeof(int) * mx_strlen(FLAGS));

    for (int i = 0; i < mx_strlen(FLAGS); i++) {
        (*flags)[i] = 0;
    }
}
