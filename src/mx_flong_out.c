#include "uls.h"

static int get_max_links(t_lstat *F) {
	int max_size = 0;

    for (; F != NULL; F = F->next)
        if (max_size < mx_strlen(mx_itoa(F->nlink)))
            max_size = mx_strlen(mx_itoa(F->nlink));
    return max_size;
}

static void p_links(t_lstat *F) {
    mx_space(get_max_links(F) - mx_strlen(mx_itoa(F->nlink)));
    mx_printint(F->nlink); // links
    mx_printstr(" ");
}

int get_max_owner(t_lstat *F) {
	int max_size = 0;

    for (; F != NULL; F = F->next)
        if (max_size < mx_strlen(F->own_name))
            max_size = mx_strlen(F->own_name);
    return max_size;
}

static void p_owner(t_lstat *F) {
    mx_printstr(F->own_name); // owner
    mx_space(get_max_owner(F) - mx_strlen(F->own_name));
    mx_printstr("  ");
}

void mx_flong_out(t_lstat *F) {
    mx_printstr(F->mode);
    mx_printstr(" ");
    p_links(F);
    p_owner(F);
}
