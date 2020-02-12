#include "uls.h"

void mx_char_swap(char **s1, char **s2) {
    char *buf = mx_strdup(*s1);

    free(*s1);
    *s1 = mx_strdup(*s2);
    free(*s2);
    *s2 = mx_strdup(buf);
    free(buf);
}
