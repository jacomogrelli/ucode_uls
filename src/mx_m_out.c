#include "uls.h"

static void printNames(t_lstat *F, int winCol) {
    int len = 0;
    int nextLen = 0;

    for (; F != NULL; F = F->next) {
        mx_printstr(F->name);
        len += mx_strlen(F->name) + 2;
        if (F->next != NULL) {
            mx_printstr(", ");
            if (F->next->next != NULL)
                nextLen = 3;
            else
                nextLen = 1;
            if (len + nextLen + mx_strlen(F->next->name) > winCol) {
                mx_printchar('\n');
                len = 0;
            }
        }
    }
    mx_printchar('\n');
}

void mx_m_out(t_lstat *F) {
    if (isatty(1))
        printNames(F, mx_get_winsize());
    else
        printNames(F, 80);
}
