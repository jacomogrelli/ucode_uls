#include "uls.h"

void mx_int_swap(int *i1, int *i2) {
    int buf = *i1;

    *i1 = *i2;
    *i2 = buf;
}
