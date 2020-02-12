#include "uls.h"

/*
 * DONE
 * Функция сортирует связанный список по ASCII
 */

void mx_sort_dirs_ascii(t_list *lst, int *flags) {
    void *tmp;

	if (!flags[mx_get_char_index(FLAGS, 'r')]) {
        for (t_list *i = lst; i->next; i = i->next)
            for (t_list *j = i->next; j; j = j->next)
                if (mx_strcmp(i->data, j->data) > 0) {
                	tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
    }
    if (flags[mx_get_char_index(FLAGS, 'r')]) {
        for (t_list *i = lst; i->next; i = i->next)
            for (t_list *j = i->next; j; j = j->next)
                if (mx_strcmp(i->data, j->data) < 0) {
                	tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
    }
}
