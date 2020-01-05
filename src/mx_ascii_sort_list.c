#include "libmx.h"

/*
 * DONE
 * Функция сортирует связанный список по ASCII
 */

t_list *mx_ascii_sort_list(t_list *lst) {
    void *tmp;

	if (!lst)
        return NULL;
    for (t_list *i = lst; i->next; i = i->next)
        for (t_list *j = i->next; j; j = j->next)
            if (mx_strcmp(i->data, j->data) > 0) {
            	tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
    return lst;
}
