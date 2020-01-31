#include "uls.h"

/*
 * DONE
 * статик more6 переделывает строку, если файлу больше 6 месяцев назад или
 * вперед от текущей даты системы
 * статик more6 переделывает строку, если последняя подификация файла в преде-
 * лах 6 месяцев от текущей даты системы
 * Функция возвращает строку с датой в зависимости от даты модификации
 */

static char *uls_date_more6(char *buf);
static char *uls_date_less6(char *buf);

char *mx_get_mtime(struct stat buf, int *flags) {
    time_t f_time;
    char *buf1 = NULL;
    char *res = NULL;
    time_t cur = time(NULL);
    time_t six_mon = 15778368; //к-во секунд в 6 месяцах

    if (flags[mx_get_char_index(FLAGS, 'u')])
        f_time = buf.st_atimespec.tv_sec;
    else
        f_time = buf.st_mtimespec.tv_sec;
    buf1 = mx_strdup(ctime(&f_time));

    if ((cur - six_mon) > f_time || (cur + six_mon) < f_time)
        res = uls_date_more6(buf1);
    else
        res = uls_date_less6(buf1);
    mx_strdel(&buf1);
    return res;
}

static char *uls_date_more6(char *buf) {
    char *res = mx_strnew(12);

    res[0] = buf[4];
    res[1] = buf[5];
    res[2] = buf[6];
    res[3] = ' ';
    res[4] = buf[8];
    res[5] = buf[9];
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

    res[0] = buf[4];
    res[1] = buf[5];
    res[2] = buf[6];
    res[3] = ' ';
    res[4] = buf[8];
    res[5] = buf[9];
    res[6] = ' ';
    res[7] = buf[11];
    res[8] = buf[12];
    res[9] = buf[13];
    res[10] = buf[14];
    res[11] = buf[15];
    return res;
}
