#include "uls.h"

/*
 * DONE
 * Функция выводит ошибки, если переданный аргумент не найден.
 */

void mx_output_error(t_list *err) {
    DIR *dptr;

    if (!err)
        return;
    mx_ascii_sort_list(err);
    while (err) {
        if ((dptr = opendir(err->data)) == NULL)
            mx_error_no_such(err->data);
        err = err->next;
    }
}
