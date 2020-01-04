#include "uls.h"

/*
 * permission дописать 13 символ
 */

t_lstat *mx_lstat_fill(struct stat buf) {
    t_lstat *res = malloc(sizeof(t_lstat));

    res->mode = mx_get_permission(buf.st_mode);
    mx_printstr(res->mode);
    res->nlink = buf.st_nlink;
    res->own_name = mx_get_owner(buf.st_uid);
    res->group = mx_get_group(buf.st_gid);
    res->size_b = buf.st_size;
    res->mtime = mx_get_mtime(buf.st_mtimespec);
    res->next = NULL;
    // system("leaks uls");
    return res;
}
