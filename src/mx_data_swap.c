#include "uls.h"

void mx_data_swap(t_lstat *s1, t_lstat *s2) {
    mx_char_swap(&s1->name, &s2->name);
    mx_char_swap(&s1->path, &s2->path);
    mx_char_swap(&s1->mode, &s2->mode);
    mx_int_swap(&s1->nlink, &s2->nlink);
    mx_char_swap(&s1->own_name, &s2->own_name);
    mx_char_swap(&s1->group, &s2->group);
    mx_char_swap(&s1->size_b, &s2->size_b);
    mx_int_swap(&s1->total, &s2->total);
    mx_char_swap(&s1->mtime, &s2->mtime);
    mx_time_swap(&s1->st_time, &s2->st_time);
    mx_size_swap(&s1->st_size, &s2->st_size);
    mx_time_swap(&s1->st_time_nsec, &s2->st_time_nsec);
}
