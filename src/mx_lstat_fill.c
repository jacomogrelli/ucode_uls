#include "uls.h"

/*
 * permission дописать 13 символ
 * Функция заполняет пользовательстуку структуру - аналог stat t_lstat
 * различными данными. При реализации новых флагов можно добавлять данные по
 * необходимости.
 */

t_lstat *mx_lstat_fill(struct stat buf, char *argv) {
    t_lstat *res = malloc(sizeof(t_lstat));

    res->path = mx_strdup(argv);
    res->name = mx_get_name(argv);
    res->mode = mx_get_permission(buf.st_mode);
    res->nlink = buf.st_nlink;
    res->size_b = buf.st_size;
    res->plink = mx_get_plink(argv, res->size_b, res->mode[0]);
    res->own_name = mx_get_owner(buf.st_uid);
    res->group = mx_get_group(buf.st_gid);
    res->mtime = mx_get_mtime(buf.st_mtimespec);
    res->next = NULL;
    // mx_printstr(res->mode);
    // system("leaks uls");
    return res;
}
