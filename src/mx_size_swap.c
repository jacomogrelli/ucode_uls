#include "uls.h"

void mx_size_swap(off_t *i1, off_t *i2) {
    off_t buf = *i1;

    *i1 = *i2;
    *i2 = buf;
}
