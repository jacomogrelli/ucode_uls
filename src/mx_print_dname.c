#include "uls.h"

void mx_print_dname(char *dname) {
    if (dname != NULL) {
        mx_printstr(dname);
        mx_printstr(":");
        mx_printstr("\n");
    }
}
