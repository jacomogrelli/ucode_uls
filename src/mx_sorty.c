#include "uls.h"

t_uls_out *mx_sorty(t_uls_out *all, int *flags) {
    t_uls_out *head = all;

    if (flags)
    while (head) {
        if (head->Dlist) {
            mx_sort_files(head->Dlist, flags);
        }
        head = head->next;
    }
    head = all;
    if (head->F)
        mx_sort_files(head->F, flags);
    return all;
}
