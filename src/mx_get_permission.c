#include "uls.h"

/*
 * Функция возвращает строку длинной 11 символов, в которую записываются пра-
 * ва доступа к файлу.
 * Статик get_mode принимает st_mode, идентификатор, для какого типа пользоват
 * елей будет происходить поиск необходимого атрибута. Далее, в зависимости от
 * идентификатора значения передаются в get_char_s или get_char_t
 *
 * НЕ РЕАЛИЗОВАНО:
 * получение последнего символа @(acl) или +(xattr)
 */

static char get_mode(mode_t st_mode, int user_type);
static char get_char_s(mode_t st_mode, int is_exec, int is_id);
static char get_char_t(mode_t st_mode, int is_exec, int is_id);

char *mx_get_permission(mode_t st_mode) {
    char *res = mx_strnew(11);

    res[0] = mx_get_perm_type(st_mode);
    res[1] = (st_mode & S_IRUSR) ? 'r' : '-';
    res[2] = (st_mode & S_IWUSR) ? 'w' : '-';
    res[3] = get_mode(st_mode, 1);
    res[4] = (st_mode & S_IRGRP) ? 'r' : '-';
    res[5] = (st_mode & S_IWGRP) ? 'w' : '-';
    res[6] = get_mode(st_mode, 2);
    res[7] = (st_mode & S_IROTH) ? 'r' : '-';
    res[8] = (st_mode & S_IWOTH) ? 'w' : '-';
    res[9] = get_mode(st_mode, 3);
    res[10] = '0';

    return res;
}

static char get_mode(mode_t st_mode, int user_type) {
    if (user_type == 1) {
        return get_char_s(st_mode, S_IXUSR, S_ISUID);
    }
    else if (user_type == 2) {
        return get_char_s(st_mode, S_IXGRP, S_ISGID);
    }
    else {
        return get_char_t(st_mode, S_IXOTH, S_ISTXT);
    }
}

static char get_char_s(mode_t st_mode, int is_exec, int is_id) {
    if (st_mode & is_exec) {
        if (st_mode & is_id)
            return 's';
        else
            return 'x';
    }
    else {
        if (st_mode & is_id)
            return 'S';
        else
            return '-';
    }
}

static char get_char_t(mode_t st_mode, int is_exec, int is_id) {
    if (st_mode & is_exec) {
        if (st_mode & is_id)
            return 't';
        else
            return 'x';
    }
    else {
        if (st_mode & is_id)
            return 'T';
        else
            return '-';
    }
}
