#include "uls.h"

/* Вызов readlink() помещает содержимое символьной ссылки pathname в буфер buf
 * размером bufsiz. readlink() не добавляет в buf байт null.
 * Если буфер слишком мал для хранения всего содержимого,
 * то содержимое будет урезано (до длины в bufsiz символов).
 * При успешном выполнении эти вызовы возвращают количество байт,
 * помещённых в buf. В случае ошибки возвращается -1,
 * а errno устанавливается в соответствующее значение.
 * В случае успеха функция возвращает путь симфольной ссылки.
 */

char *mx_get_plink(char *argv, unsigned long size_b, char p) {
    char *buf = NULL;
    ssize_t len = 0;

    if (p != 'l')
        return "\0";
    buf = mx_strnew(size_b);
    if ((len = readlink(argv, buf, size_b)) < 0) {
        mx_strdel(&buf);
        return "\0";
    }
    return buf;
}
