#include "uls.h"

t_uls_out *mx_t_uls_out_init(t_uls_out *all) {
    all->next = malloc(sizeof(t_uls_out));
    all = all->next;
    all->E = NULL;
    all->F = NULL;
    all->D = NULL;
    all->Dlist = NULL;
    all->next = NULL;
    return all;
}
