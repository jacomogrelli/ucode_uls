#include "uls.h"

static void int_swap(int i1, int i2) {
    int buf = i1;

    i1 = i2;
    i2 = buf;
}

static void char_swap(char **s1, char **s2) {
    char *buf = mx_strdup(*s1);

    *s1 = mx_strdup(*s2);
    *s2 = mx_strdup(buf);
    free(buf);
}

static void data_swap(t_lstat *s1, t_lstat *s2) {

    char_swap(&s1->name, &s2->name);
    char_swap(&s1->path, &s2->path);
    char_swap(&s1->mode, &s2->mode);
    int_swap(s1->nlink, s2->nlink);
    char_swap(&s1->own_name, &s2->own_name);
    char_swap(&s1->group, &s2->group);
    char_swap(&s1->size_b, &s2->size_b);
    int_swap(s1->total, s2->total);
    char_swap(&s1->mtime, &s2->mtime);
}

static void sort_list(t_lstat *head) {
    for (t_lstat *i = head; i->next; i = i->next) {
        for (t_lstat *j = i->next; j; j = j->next) {
            if (mx_strcmp(i->name, j->name) > 0)
                data_swap(i, j);
        }
    }
}

t_uls_out *mx_sorty(t_uls_out *all, int *flags) {
    t_uls_out *head = all;

    if (flags)
    while (head) {
        if (head->Dlist) {
            sort_list(head->Dlist);
        }
        head = head->next;
    }
    head = all;
    if (head->F)
        sort_list(head->F);
    return all;
}
