#include "uls.h"

void mx_output_folders(t_uls_out *all, int *flags, int ac, int flag) {
    t_list *dirs = all->D;
    t_uls_out *dlist = all;
    DIR *dp;

    if (!all->D)
        return;
    while (dirs) {
        if (ac != flag && ac != flag + 1)
            mx_print_dname(dirs->data);
        if (!(dp = opendir(dirs->data))) {
            mx_error_pd(dirs->data);
            all->err = true;
            if (dirs->next)
                mx_printchar('\n');
        }
        else {
            if ((flags[mx_get_char_index(FLAGS, 'l')] ||
                flags[mx_get_char_index(FLAGS, 'o')]) && dlist->Dlist) {
                    mx_output_total(dlist->Dlist);
            }
            mx_output_files(dlist->Dlist, flags);
            if (dlist->next->next)
                mx_printchar('\n');
            closedir(dp);
        }
        dirs = dirs->next;
        dlist = dlist->next;
    }
}
