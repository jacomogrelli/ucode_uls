#include "uls.h"

void mx_error_pd(char *argv) {
    char *str = mx_memrchr(argv, '/', mx_strlen(argv));
    char *err_buf = mx_strjoin("uls: ", str + 1);

    perror(err_buf);
    free(err_buf);
    return;
}
