#include "uls.h"

/*
 * DONE
 * Функция получает из аргумента argv имя конкретного файла,
 * исключая путь к нему.
 */

char *mx_get_name(char *argv, int *flags, struct stat buf, bool r) {
    char *res = NULL;
    int len = mx_strlen(argv);
    int name_len = 0;
    if (r) {
        if (argv[len - 1] == '/')
            len -= 1;
        for (int i = len - 1; i >= 0 && argv[i] != '/'; i--) {
            name_len++;
        }
        if (name_len != 0)
            res = mx_strndup(argv + (len - name_len), name_len);
        if (name_len == 0)
            res = mx_strdup("/");
        if (flags[mx_get_char_index(FLAGS, 'F')])
            res = mx_flag_F(res, buf);
    }
    if (!r) {
        res = mx_strdup(argv);
        if (flags[mx_get_char_index(FLAGS, 'F')])
            res = mx_flag_F(res, buf);
    }
    return res;
}
