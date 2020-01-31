#include "uls.h"

static t_uls_out *uls_res_init();

t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags) {
    struct stat buf;
    t_uls_out *res = uls_res_init();
if (flags != NULL) // delete
    if (argc == flag) {
        mx_push_back(&res->D, ".");
        return res;
    }
    for (;flag < argc; flag++) {
        if (lstat(argv[flag], &buf) < 0)
           mx_push_back(&res->E, argv[flag]);
        else {
            if (MX_ISDIR(buf.st_mode))
                mx_push_back(&res->D, argv[flag]);
            else
                mx_push_stat(&res->F, mx_lstat_fill(buf, argv[flag], flags));
        }
    }
    return res;
}

static t_uls_out *uls_res_init(void) {
    t_uls_out *res = malloc(sizeof(t_uls_out));

    res->E = NULL;
    res->F = NULL;
    res->D = NULL;
    res->Dlist = NULL;
    return res;
}


// t_uls_out *A_flag(int ac, )
