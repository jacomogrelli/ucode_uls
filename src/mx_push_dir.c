#include "uls.h"

void mx_push_dir(t_list **list, void *data) {
    t_list* back = malloc(sizeof(t_list));
    t_list* tmp = NULL;

    if (!list)
         return ;
    back->data = mx_strdup((char *)data);
    back->next = NULL;
    if (!back)
         return;
    tmp = *list;
    if (*list == NULL) {
       *list = back;
       return ;
    }
    while (tmp->next != NULL)
           tmp = tmp->next;
    tmp->next = back;
}
