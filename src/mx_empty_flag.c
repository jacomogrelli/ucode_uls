#include "uls.h"

/*

*/

void mx_empty_flag(void) {
    DIR *dirp;
    t_list *list = NULL;
    t_list *HEAD = NULL;
    struct dirent *buf;

    dirp = opendir(".");
    while ((buf = readdir(dirp)) != NULL) {
        if (buf->d_name[0] != '.')
            mx_push_back(&list, buf->d_name);
    }
    if (closedir(dirp) < 0)
        exit(-1);
    list = mx_ascii_sort_list(list);
    HEAD = list;
    while (HEAD) {
        printf("%s  ", HEAD->data);
        HEAD = HEAD->next;
    }
    system("leaks uls");
    exit(0);
}
