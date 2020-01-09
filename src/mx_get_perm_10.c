#include "uls.h"

/*
 * DONE
 * Фунция возвразает 10 символ строки mode.
 */

char mx_get_perm_10(char *path) {
    ssize_t xattr;
    acl_t acl;

    if ((xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0)
        return '@';
    if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != (acl_t)NULL) {
        acl_free(acl);
        return '+';
    }
    return ' ';
}
