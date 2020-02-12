#include "uls.h"

void mx_time_swap(time_t *i1, time_t *i2) {
    time_t buf = *i1;

    *i1 = *i2;
    *i2 = buf;
}
