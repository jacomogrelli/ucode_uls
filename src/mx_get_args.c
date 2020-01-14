#include "uls.h"

static t_uls_out *uls_res_init();

t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags) {
    struct stat buf;
    t_uls_out *res = uls_res_init();
    t_lstat *temp = NULL;

    if (flags != NULL) //временная хуйня, убрать


    if (argc == 1 || (argc == 2 && mx_strcmp(argv[1], "--") == 0))
        mx_empty_flag();

    for (;flag < argc; flag++) {
        if (lstat(argv[flag], &buf) < 0)
           mx_push_back(&res->errors, argv[flag]);
        temp = mx_lstat_fill(buf, argv[flag]);
        if (MX_ISDIR(buf.st_mode))
            mx_push_back(&res->folders, temp);
        mx_push_back(&res->files, temp);
        mx_free_t_lstat(temp);
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
