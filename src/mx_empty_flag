#include "uls.h"

/*
 * DONE
 * функция опендир возвращает указатель на структуру
 * типа dirrent (описание структуры есть в uls.h)
 * reeddir в цикле считывает данные d_name (имя
 * файла и дирректории), исключая скрытые файлы
 * (нулевой элемент d_name ".").
 */

t_list *mx_empty_flag(int *flags) {
    DIR *dirp;
    t_list *list = NULL;
    struct dirent *buf;

    dirp = opendir(".");
    while ((buf = readdir(dirp)) != NULL) {
        if (flags[mx_get_char_index(FLAGS, 'a')])
            mx_push_back(&list, buf->d_name);
        if (flags[mx_get_char_index(FLAGS, 'A')]) {
            if (mx_strcmp(buf->d_name, ".") != 0 &&
                mx_strcmp(buf->d_name, "..") != 0)
                mx_push_back(&list, buf->d_name);
        }
        if (buf->d_name[0] != '.')
            mx_push_back(&list, buf->d_name);
    }
    if (closedir(dirp) < 0)
        exit(-1);
    return list;
}
