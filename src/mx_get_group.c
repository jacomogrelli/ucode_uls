#include "uls.h"

/*
* функция возвращает имя группы или ее id, если она не доступна пользо
* вателю
*/

char *mx_get_group(gid_t st_gid) {
    char *res;
    struct group *buf;

    if ((buf = getgrgid(st_gid)) == NULL)
        res = mx_itoa(st_gid);
    else
        res = mx_strdup(buf->gr_name);
    return res;
}
