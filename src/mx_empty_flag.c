#include "uls.h"

/*

*/

void mx_empty_flag(int argc, int flag_count, char **argv) {
    struct stat buf;
    // t_uls_out res;
    // char *res;

    for (int res; flag_count < argc; flag_count++) {
        res = lstat(argv[flag_count], &buf);
        if ((buf.st_mode & S_IFMT) == S_IFDIR)
        printf("huisya");

    }

}
