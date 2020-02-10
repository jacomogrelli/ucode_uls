#include "uls.h"

char *mx_struct_index(t_lstat *F, int i) {
    for (int j = 0; j != i; j++, F = F->next)
        if (j == i)
            return F->name;
    return F->name;
}
