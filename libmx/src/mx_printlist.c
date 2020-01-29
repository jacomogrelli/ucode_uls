#include "libmx.h"

void mx_printlist(t_list *list) {
    t_list *head = list;

    while (head->next != NULL) {
        mx_printstr(head->data);
        mx_printstr(" ");
        head = head->next;
    }
    mx_printstr(head->data);
}
