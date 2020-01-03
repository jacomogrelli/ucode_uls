#include "uls.h"

/*
* статик more6 переделывает строку, если файлу больше 6 месяцев назад или
* вперед от текущей даты системы
* статик more6 переделывает строку, если последняя подификация файла в преде-
* лах 6 месяцев от текущей даты системы
* Функция возвращает строку с датой в зависимости от даты модификации
*/

static char *uls_date_more6(char *buf);
static char *uls_date_less6(char *buf);

char *mx_get_mtime(struct timespec stmtime) {
    char *buf = mx_strdup(ctime(&stmtime.tv_sec));
    char *res = NULL;
    time_t cur = time(NULL);
    time_t six_mon = 15778368; //к-во секунд в 6 месяцах

    if ((cur - six_mon) > stmtime.tv_sec || (cur + six_mon) < stmtime.tv_sec)
        res = uls_date_more6(buf);
    else
        res = uls_date_less6(buf);
    mx_strdel(&buf);
    return res;
}

static char *uls_date_more6(char *buf) {
    char *res = mx_strnew(12);

    res[0] = buf[8];
    res[1] = buf[9];
    res[2] = ' ';
    res[3] = buf[4] + 32;
    res[4] = buf[5];
    res[5] = buf[6];
    res[6] = ' ';
    res[7] = ' ';
    res[8] = buf[20];
    res[9] = buf[21];
    res[10] = buf[22];
    res[11] = buf[23];
    return res;
}

static char *uls_date_less6(char *buf) {
    char *res = mx_strnew(12);

    res[0] = buf[8];
    res[1] = buf[9];
    res[2] = ' ';
    res[3] = buf[4] + 32;
    res[4] = buf[5];
    res[5] = buf[6];
    res[6] = ' ';
    res[7] = buf[11];
    res[8] = buf[12];
    res[9] = buf[13];
    res[10] = buf[14];
    res[11] = buf[15];
    return res;
}
