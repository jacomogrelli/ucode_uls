#include "uls.h"

/*
 * функция возвращает первый символ строки прав доступа для определения
 * типа файла.
 * Так же может использоваться в других флагах для определения типа файла.
 */

char mx_get_perm_type(mode_t st_mode) {
    if (MX_ISBLK(st_mode))
        return 'b';
    if (MX_ISCHR(st_mode))
        return 'c';
    if (MX_ISDIR(st_mode))
        return 'd';
    if (MX_ISFIFO(st_mode))
        return 'p';
    if (MX_ISLNK(st_mode))
        return 'l';
    if (MX_ISSOCK(st_mode))
        return 's';
    return '-';
}
