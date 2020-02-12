#include "uls.h"

static void ascii_swap(t_list *i, t_list *j, int *flags) {
    void *tmp;

    if (!flags[mx_get_char_index(FLAGS, 'r')])
        if (mx_strcmp(i->data, j->data) > 0) {
                    tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
     if (flags[mx_get_char_index(FLAGS, 'r')])
        if (mx_strcmp(i->data, j->data) < 0) {
                    tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
}

void mx_sort_dirs_utime(t_list *dirs, int *flags) {
    struct stat ibuf;
    struct stat jbuf;
    void *tmp;
    int r = flags[mx_get_char_index(FLAGS, 'r')];

    for (t_list *i = dirs; i->next; i = i->next)
        for (t_list *j = i->next; j; j = j->next)
            if (!(lstat(i->data, &ibuf)) && !(lstat(j->data, &jbuf))) {
            	if (r) {
                    if (ibuf.st_atimespec.tv_sec > jbuf.st_atimespec.tv_sec) {
                        tmp = i->data;
                        i->data = j->data;
                        j->data = tmp;
                    }
                    if (ibuf.st_atimespec.tv_sec == jbuf.st_atimespec.tv_sec)
                        ascii_swap(i, j, flags);
                }
                if (!r) {
                    if (ibuf.st_atimespec.tv_sec < jbuf.st_atimespec.tv_sec) {
                        tmp = i->data;
                        i->data = j->data;
                        j->data = tmp;
                    }
                    if (ibuf.st_atimespec.tv_sec == jbuf.st_atimespec.tv_sec)
                        ascii_swap(i, j, flags);
                }
    }
}
