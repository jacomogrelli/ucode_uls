#include "uls.h"

/*
 * Function print to error output massage "uls: [name]: No such file..."
 */

void mx_error_no_such(char *argv) {
    char *err_buf = mx_strjoin("uls: ", argv);

    perror(err_buf);
    free(err_buf);
    return;
}
