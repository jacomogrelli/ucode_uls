#include "uls.h"

t_lstat *mx_asort_lstat(t_lstat *lst) {
    void *tmp;

	if (!lst)
        return NULL;
    for (t_lstat *i = lst; i->next; i = i->next)
        for (t_lstat *j = i->next; j; j = j->next)
            if (mx_strcmp(i->path, j->path) > 0) {
            	tmp = i->path;
                i->path = j->path;
                j->path = tmp;
            }
    return lst;
}
