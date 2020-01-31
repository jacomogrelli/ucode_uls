#include "uls.h"

int mx_get_total(struct stat buf) {
    int res = buf.st_blocks;

    return res;
}
