#include "uls.h"

int main (int argc, char **argv) {
    int *flags = NULL;
    int flag_count = mx_flag_check(argc, argv, &flags);
    t_uls_out *all = NULL;

    all = mx_get_args(argc, flag_count, argv, flags);
    all = mx_get_dirlist(all, flags);
    all = mx_sorty(all, flags);
    mx_output_error(all->E);
    mx_output_files(all->F, flags);
    mx_output_folders(all, flags, argc, flag_count);
    mx_uls_cleaner(all);
    if (all->E || all->err)
        return 1;
    return 0;
}
