#include "uls.h"

static t_uls_out *uls_res_init(void) {
    t_uls_out *res = malloc(sizeof(t_uls_out));

    res->E = NULL;
    res->F = NULL;
    res->D = NULL;
    res->Dlist = NULL;
    res->next = NULL;
    return res;
}

static t_uls_out *uls_flag_D(struct stat buf, int *flags, t_uls_out *res,
char *name) {
    if (flags[mx_get_char_index(FLAGS, 'd')]) {
        if (lstat(name, &buf) >= 0) {
            mx_push_stat(&res->F, mx_lstat_fill(buf, name, flags, false));
            return res;
        }
    }
    mx_push_back(&res->D, name);
    return res;
}

t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags) {
    struct stat buf;
    t_uls_out *res = uls_res_init();

    if (argc == flag) {
        if (lstat(".", &buf) >= 0)
            res = uls_flag_D(buf, flags, res, ".");
    }
    for (;flag < argc; flag++) {
        if (lstat(argv[flag], &buf) < 0)
           mx_push_back(&res->E, argv[flag]);
        else {
            if (MX_ISDIR(buf.st_mode))
                res = uls_flag_D(buf, flags, res, argv[flag]);
            else
                mx_push_stat(&res->F, mx_lstat_fill(buf, argv[flag], flags, false));
        }
    }
    if (flags[mx_get_char_index(FLAGS, 'R')])
        res->D = mx_R(res->D, flags);
    mx_ascii_sort_list(res->D);
    return res;
}
