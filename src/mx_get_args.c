#include "uls.h"

static t_uls_out *uls_res_init();

t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags) {
    struct stat buf;
    t_uls_out *res = uls_res_init();
if (flags != NULL) // delete 
    if (argc == flag) {
        mx_push_back(&res->folders, ".");
        return res;
    }
    for (;flag < argc; flag++) {
        if (lstat(argv[flag], &buf) < 0)
           mx_push_back(&res->errors, argv[flag]);
        if (MX_ISDIR(buf.st_mode))
            mx_push_back(&res->folders, argv[flag]);
        else
            mx_push_stat(&res->files, mx_lstat_fill(buf, argv[flag]));
    }
    return res;
}

static t_uls_out *uls_res_init(void) {
    t_uls_out *res = malloc(sizeof(t_uls_out));

    res->errors = NULL;
    res->files = NULL;
    res->folders = NULL;
    return res;
}
