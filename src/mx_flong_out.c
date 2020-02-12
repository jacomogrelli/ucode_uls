#include "uls.h"

static void p_links(t_lstat *F, int max_links) {
    char *k = mx_itoa(F->nlink);

    mx_space(max_links - mx_strlen(k));
    mx_printint(F->nlink); // links
    mx_printstr(" ");
    free(k);
}

static void p_owner(t_lstat *F, int max_own) {
    int sum = max_own - mx_strlen(F->own_name);

    mx_printstr(F->own_name); // owner
    if (sum == mx_strlen(F->own_name))
        mx_printstr("  ");
    else
        mx_space(sum);
        mx_printstr("  ");

}

void mx_flong_out(t_lstat *F, int max_links, int max_own) {
    mx_printstr(F->mode);
    mx_printstr(" ");
    p_links(F, max_links);
    p_owner(F, max_own);
}
