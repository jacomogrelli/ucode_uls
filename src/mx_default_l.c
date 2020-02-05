#include "uls.h"

void mx_default_l(t_lstat *o) {
     for (; o != NULL; o = o->next) {
        // mx_printint(o->total);
        // mx_printstr("\n");
        mx_printstr(o->mode);
        mx_printstr(" ");
        mx_printint(o->nlink);
        mx_printstr(" ");
        mx_printstr(o->own_name);
        mx_printstr(" ");
        mx_printstr(o->plink);
        mx_printstr(" ");
        mx_printstr(o->group);
        mx_printstr("  ");
        mx_printstr(o->size_b);
        mx_printstr(" ");
        mx_printstr(o->mtime);
        mx_printstr(" ");
        mx_printstr(o->name);
        mx_printstr("\n");
        mx_free_t_lstat(o);
    }
}
