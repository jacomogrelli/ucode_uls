#include "uls.h"

void mx_uls_cleaner(t_uls_out *all) {
    for (;all; all = all->next) {
        for (;all->Dlist; all->Dlist = all->Dlist->next) {
            free(all->Dlist->name);
            free(all->Dlist->path);
            free(all->Dlist->mode);
            if (all->Dlist->plink[0] != '\0')
                free(all->Dlist->plink);
            free(all->Dlist->own_name);
            free(all->Dlist->group);
            free(all->Dlist->size_b);
            free(all->Dlist->mtime);
            free(all->Dlist);
        }
    }
    free(all);
    return;
}
