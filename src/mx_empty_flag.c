#include "uls.h"

/*
* функция опендир возвращает указатель на структуру
* типа dirrent (описание структуры есть в uls.h)
* reeddir в цикле считывает данные d_name (имя
* файла и дирректории), исключая скрытые файлы
* (нулевой элемент d_name "."). Затем связанный
* связанный список сортируется в mx_ascii_sort
* HEAD - указатель на начало листа для печати, глобально
* мусорная переменная, будет удалена.
*
* в дальнейшем после реализации вывода добавить передачу
* листа в функцию вывода
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
