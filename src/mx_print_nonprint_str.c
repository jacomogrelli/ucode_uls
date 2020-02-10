#include "uls.h"

void mx_print_nonprint_str(const char *s) {
    char tmp = '?';
    int i = 0;
    if (s) {
        while (s[i]) {
            if (s[i] > 31 && s[i] < 127)
                write(1, &s[i], 1);
            else
                write(1, &tmp, 1);
            i++;
        }
    }
}
