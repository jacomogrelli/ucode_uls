#include "uls.h"

void mx_basic(int argc, char **argv, int flag_count) {
    struct stat buf;
    t_uls_out *res;

    for (;flag_count < argc; flag_count++) {
        if (lstat(argv[flag_count], &buf) == -1)
            mx_push_back(res->errors, argv[flag_count]);
        char mode[] = buf.st_mode;
        printf("%s\n", mode);
    }
}
