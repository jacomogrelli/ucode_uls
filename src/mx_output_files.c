#include "uls.h"

void default_l(t_lstat *o);
void arg_l(t_lstat *o, int *flags, t_list *D);

void mx_output_files(t_lstat *out, int *flags) {
    if (!flags) return; //временная ХУЙНЯ убрать
// mx_ascii_sort_list(out);
    if (flags[mx_get_char_index(FLAGS, 'l')])
        mx_default_l(out);
    // if (flags[mx_get_char_index(FLAGS, 'l')])
    //     arg_l(out, flags, D);
    // while (out) {
    //     mx_printstr(" ");
    //     mx_printstr(out->name);
    //     out = out->next;

    // }
}

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

// void arg_l(t_lstat *o, int *flags, t_list *D) {
//     DIR *dirp;
//     struct dirent *dbuf;
//     struct stat buf;
//     struct stat *fill = NULL;

//     if (!(dirp = opendir(D->data)))
//         exit(1);
//     while ((dbuf = readdir(dirp)) != NULL) {
//         lstat(D->data, &buf);
//         mx_lstat_fill(*fill, dbuf->d_name, flags);
//         default_l(o);
//     }
//     if (closedir(dirp) < 0)
//         exit(1);
// }
