#include "uls.h"

static void uls_err_illegal_option(char c);

void mx_flag_check(int argc, char **argv) {
    if (argc == 1)
        return;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-')
            return;
        for (int j = 1; argv[i][j]; j++) {
            if (mx_get_char_index(FLAGS, (argv[i][j])) == -1)
                uls_err_illegal_option(argv[i][j]);
        }
    }
    return;
}

static void uls_err_illegal_option(char c) {
    mx_printerr("uls: illegal option -- ");
    write(2, &c, 1);
    mx_printerr("\nusage: ls [-");
    mx_printerr(FLAGS);
    mx_printerr("] [file ...]\n");
    exit (1);
}
