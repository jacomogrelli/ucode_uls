#include "uls.h"

/*
 * DONE
 * Функция возвращает строку вормата первоеимся/второеимя
 */

char *mx_namejoin(char *name1, char *name2) {
    char *res = NULL;
    char *buf = NULL;

    if (name1[mx_strlen(name1) - 1] != '/') {
        buf = mx_strnew(mx_strlen(name1) + 1);
        buf = mx_strcat(mx_strcpy(buf, name1), "/");
        res = mx_strnew(mx_strlen(buf) + mx_strlen(name2) + 1);
        res = mx_strcat(mx_strcpy(res, buf), name2);
        mx_strdel(&buf);
    }
    else {
        res = mx_strnew(mx_strlen(name1) + mx_strlen(name2));
        res = mx_strcat(name1, name2);
    }
	return res;
}
