#include "uls.h"

int mx_get_max_size(t_lstat *N) {
	int max_size = 0;

    for (t_lstat *F = N; F != NULL; F = F->next)
        if (max_size < mx_strlen(F->size_b)) {
        	if (mx_get_char_index(F->size_b, ',') > 0) {
        		if (max_size <= 8)
        			max_size = 8;
            }
            else
            	max_size = mx_strlen(F->size_b);
        }
    return max_size;
}
