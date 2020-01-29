#include "uls.h"

void mx_output_folders(t_uls_out *out, int *flags) {
    if (!flags) return;

    while (out->folders) {
        printf("%s ", out->folders->data);

        out->folders = out->folders->next;
    }
}
