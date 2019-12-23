#include "uls.h"

/*
* починить сигфолт на пушбек
*/

void mx_empty_flag(int argc, int flag_count, char **argv) {
    struct stat buf;
    t_uls_out *result = malloc(sizeof(t_uls_out));
    // char *res;


    for (int res; flag_count < argc; flag_count++) {
        res = lstat(argv[flag_count], &buf);
        if (res == -1)
            mx_push_front(&result->errors, argv[flag_count]);
        if ((buf.st_mode & S_IFMT) == S_IFDIR)
            mx_push_front(&result->folders, argv[flag_count]);
        if ((buf.st_mode & S_IFMT) == S_IFREG)
            mx_push_front(&result->files, argv[flag_count]);
    }
}
