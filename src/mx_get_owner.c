#include "uls.h"

/*
 * DONE
 * функция возвращает имя пользователя или его id, если пользователю оно
 * не доступно
 */

char *mx_get_owner(uid_t st_uid) {
    char *res = NULL;
    struct passwd *temp;

    if ((temp = getpwuid(st_uid)) == NULL)
        res = mx_itoa(st_uid);
    else
        res = mx_strdup(temp->pw_name);
    return res;
}
