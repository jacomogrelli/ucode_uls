#include "uls.h"

/*
 * ДОБАВЛЯТЬ ЭЛЕМЕНТЫ СТРУКТУРЫ t_lstat
 * Функция очищает структуру.
 */

void mx_free_t_lstat(t_lstat *temp) {
    if (!temp)
        return;
    mx_strdel(&temp->name);
    mx_strdel(&temp->path);
    mx_strdel(&temp->mode);
    if (mx_strcmp(temp->plink, "\0") != 0)
        mx_strdel(&temp->plink);
    mx_strdel(&temp->own_name);
    mx_strdel(&temp->group);
    mx_strdel(&temp->size_b);
    mx_strdel(&temp->mtime);
    temp = NULL;
}
