#include "uls.h"

/*
 * DONE
 * Функция получает из аргумента argv имя конкретного файла,
 * исключая путь к нему.
 */

char *mx_get_name(char *argv) {
    char *res = NULL;
    int len = mx_strlen(argv);
    int name_len = 0;

    if (argv[len - 1] == '/')
        len -= 1;
    for (int i = len - 1; i >= 0 && argv[i] != '/'; i--) {
        name_len++;
    }
    res = mx_strndup(argv + (len - name_len), name_len);
    return res;
}
