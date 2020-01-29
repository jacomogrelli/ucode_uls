#include "uls.h"

void mx_push_stat(t_lstat **list, void *data) {
    t_lstat *back = NULL;
    t_lstat *tmp = NULL;

    if (!list)
         return;
    back = data;
    if (!back)
         return;
    tmp = *list;
    if (*list == NULL) {
       *list = back;
       return;
    }
    while (tmp->next != NULL)
           tmp = tmp->next;
    tmp->next = back;
}
