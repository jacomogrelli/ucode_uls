#include "uls.h"
/*
* mx_lstat_fill заполняет структуру со всеми данными о файле
*/
static t_uls_out *uls_res_init();

void mx_basic(int argc, char **argv, int flag_count) {
    struct stat buf;
    t_uls_out *res = uls_res_init();
    t_lstat *temp = NULL;

    for (;flag_count < argc; flag_count++) {
        if (stat(argv[flag_count], &buf) < 0)
           mx_push_back(&res->errors, argv[flag_count]);
        temp = mx_lstat_fill(buf);
    }


//    t_list *HEAD = res->errors;
//     while (HEAD) {
//         mx_error_no_such(HEAD->data);
//         HEAD = HEAD->next;
//     }
    // exit (0);
}

static t_uls_out *uls_res_init(void) {
    t_uls_out *res = malloc(sizeof(t_uls_out));

    res->errors = NULL;
    res->files = NULL;
    res->folders = NULL;
    return res;
}
