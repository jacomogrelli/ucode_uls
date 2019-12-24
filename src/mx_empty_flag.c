#include "uls.h"

/*
* починить сигфолт на пушбек
*/

void mx_empty_flag(void) {
    DIR *dirp;
    t_list *list = malloc(sizeof(t_list));
    t_list *HEAD = list;
    struct dirent *buf;

    dirp = opendir(".");
    while ((buf = readdir(dirp)) != 0) {
        mx_push_front(&list, buf->d_name);
        // printf("%s - ", list->data);
        // list = list->next;
    }
    if (closedir(dirp) < 0)
        exit(-1);
    list = HEAD;
    printf("%s  ", list->data);
    while (list) {
        printf("%s  ", list->data);
        list = list->next;
    }
    exit(0);
}
