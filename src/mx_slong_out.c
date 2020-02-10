#include "uls.h"

static void p_group(t_lstat *F, int *flags, int max_gr) {
    if (!flags[mx_get_char_index(FLAGS, 'o')]) {
        mx_printstr(F->group);
        mx_space(max_gr - mx_strlen(F->group));
        mx_printstr("  ");
    }
}

static void p_size(t_lstat *F, int *flags, int max_size) {
    if (max_size - mx_strlen(F->size_b) < 0 &&
        flags[mx_get_char_index(FLAGS, 'o')])
        mx_printstr(" ");
    else if (max_size - mx_strlen(F->size_b) < 0)
        mx_printstr(" ");
    mx_space(max_size - mx_strlen(F->size_b));
    mx_printstr(F->size_b);
    mx_printstr(" ");
}

static void p_time(t_lstat *F) {
    mx_printstr(F->mtime);
    mx_printstr(" ");
}

static void p_link(t_lstat *F) {
    if (F->mode[0] == 'l') { // links
        size_t linklen;
        linklen = readlink(F->path, NULL, 20000);
        if (linklen != 0) {
            char *link  = malloc(10000);
            linklen = readlink(F->path, link, linklen);
            link[linklen] = '\0';
            mx_printstr(" -> ");
            mx_printstr(link);
            free(link);
        }
    }
}

void mx_slong_out(t_lstat *F, int *flags, int max_size, int max_gr) {
    p_group(F, flags, max_gr);
    p_size(F, flags, max_size);
    p_time(F);
    mx_printstr(F->name);
    p_link(F);
    mx_printstr("\n");
}
