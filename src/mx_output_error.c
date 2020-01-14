#include "uls.h"

/*
 * DONE
 * Функция выводит ошибки, если переданный аргумент не найден.
 */

void mx_output_error(t_list *err) {
    if(!err)
        return;
    mx_ascii_sort_list(err);
    while(err) {
        mx_error_no_such(err->data);
        err = err->next;
    }
    return;
}
