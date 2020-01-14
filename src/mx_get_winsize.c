#include "uls.h"

/*
 * DONE
 * Функция возвращает размер окна в символах.
 */

int mx_get_winsize(void) {
    struct winsize buf;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &buf);
    return buf.ws_col;
}
