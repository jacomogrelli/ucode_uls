#include "uls.h"

static t_uls_out *uls_res_init();

void mx_basic(int argc, char **argv, int flag_count) {
    struct stat buf;
    t_uls_out *res = uls_res_init();

    for (;flag_count < argc; flag_count++) {
        int i = lstat(argv[flag_count], &buf);
        printf("%d\n", i);
        if (i < 0)
           mx_push_back(&res->errors, argv[flag_count]);
    }


   t_list *HEAD = res->errors;
    while (HEAD) {
        mx_error_no_such(HEAD->data);
        HEAD = HEAD->next;
    }
    // exit (0);
}

static t_uls_out *uls_res_init(void) {
    t_uls_out *res = malloc(sizeof(t_uls_out));

    res->errors = NULL;
    res->files = NULL;
    res->folders = NULL;
    return res;
}
