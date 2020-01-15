#include "uls.h"

void mx_output_files(t_list *files, int *flags) {
    if (!files)
        return;
    if (!flags) return; //временная ХУЙНЯ убрать
mx_ascii_sort_list(files);
while(files) {
    printf("%s  ", files->data);
    files = files->next;
}
}
