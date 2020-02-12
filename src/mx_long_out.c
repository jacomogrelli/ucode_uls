#include "uls.h"

static int get_max_links(t_lstat *F) {
	int max_size = 0;
    char *k = NULL;

    for (; F != NULL; F = F->next) {
        k = mx_itoa(F->nlink);
        if (max_size < mx_strlen(k))
            max_size = mx_strlen(k);
        free(k);
    }
    return max_size;
}

int get_max_owner(t_lstat *F) {
	int max_size = 0;

    for (; F != NULL; F = F->next)
        if (max_size < mx_strlen(F->own_name))
            max_size = mx_strlen(F->own_name);
    return max_size;
}

void mx_long_out(t_lstat *F, int *flags) {
    int max_size = mx_get_max_size(F);
    int max_gr = mx_get_max_group(F);
    int max_links = get_max_links(F);
    int max_own = get_max_owner(F);

    for (; F != NULL; F = F->next) {
        mx_flong_out(F, max_links, max_own);
        mx_slong_out(F, flags, max_size, max_gr);
    }
}
