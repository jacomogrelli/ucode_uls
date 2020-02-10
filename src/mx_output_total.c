#include "uls.h"

void mx_output_total(t_lstat *Dlist) {
    int i = 0;

    if (!Dlist)
        return;
    while (Dlist) {
        i += Dlist->total;
        Dlist = Dlist->next;
    }
    mx_printstr("total ");
    mx_printint(i);
    mx_printchar('\n');
    return;
}
