#include "uls.h"

int mx_get_max_group(t_lstat *F) {
	int max_size = 0;

    for (; F != NULL; F = F->next)
        if (max_size < mx_strlen(F->group))
            max_size = mx_strlen(F->group);
    return max_size;
}
