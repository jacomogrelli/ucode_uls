#include "uls.h"
static void error_dir (t_list *dirs, t_uls_out *all) {
    mx_error_pd(dirs->data);
    all->err = true;
    if (dirs->next)
        mx_printchar('\n');
}

static void p_dir(t_uls_out *dlist, int *flags, DIR *dp) {
    if ((flags[mx_get_char_index(FLAGS, 'l')] ||
         flags[mx_get_char_index(FLAGS, 'o')]) && dlist->Dlist)
         mx_output_total(dlist->Dlist);
    mx_output_files(dlist->Dlist, flags);
    if (dlist->next->next)
        mx_printchar('\n');
        closedir(dp);
}

void mx_output_folders(t_uls_out *all, int *flags, int ac, int flag) {
    t_uls_out *dlist = all;
    DIR *dp;
    bool mark = false;

    if (!all->D)
        return;
    if (all->D && all->F)
        mx_printchar('\n');
    for (t_list *dirs = all->D; dirs != NULL; dirs = dirs->next) {
        if (ac != flag && ac != flag + 1 && !mark)
            mx_print_dname(dirs->data);
        if (mark)
            mx_print_dname(dirs->data);
        mark = true;
        if (!(dp = opendir(dirs->data)))
            error_dir(dirs, all);
        else
            p_dir(dlist, flags, dp);
        dlist = dlist->next;
    }
}
