#include "uls.h"

/*
 * DONE
 * Функция возвращает строку размера файла в байтах.
 * Либо, если тип файла b или с, колличесто мажоров и миноров файла в виде
 * строки. На тестах не может совпадать, т.к. это число постоянно меняется.
 * В хедере передефайнены макросы для получения мажора MX_GETMAJ
 * и минора MX_GETMIN (понять суть их работы не удалость,
 * тупо переписал библиотечные)
 */

static char *get_minor(dev_t rdev);
static char *get_hex(int size, char *res);
static char *get_int(int size, char *res);

char *mx_get_size(struct stat buf) {
    char *res_ma = NULL;
    char *res_mi = NULL;
    char *res = NULL;

    if (MX_ISBLK(buf.st_mode) || MX_ISCHR(buf.st_mode)) {
        res_ma = mx_itoa(MX_GETMAJ(buf.st_rdev));
        res_mi = get_minor(buf.st_rdev);
        res = mx_strjoin(res_ma, res_mi);
        mx_strdel(&res_ma);
        mx_strdel(&res_mi);
        return res;
    }
    else
        return mx_itoa(buf.st_size);
}

static char *get_minor(dev_t rdev) {
    if (MX_GETMIN(rdev) > 256) {
        return get_hex(12, mx_nbr_to_hex(MX_GETMIN(rdev)));
    }
    return get_int(5, mx_itoa(MX_GETMIN(rdev)));
}

static char *get_hex(int size, char *res) {
    char *hex = mx_strnew(size);
    int len = size - mx_strlen(res);

    hex[0] = ',';
    hex[1] = ' ';
    for (int i = 2, j = 0; i < size; i++) {
        hex[i] = '0';
        if (i == 1)
            hex[i] = 'x';
        if (i >= len) {
            hex[i] = res[j];
            j++;
        }
    }
    mx_strdel(&res);
    return hex;
}

static char *get_int(int size, char *res) {
    char *hex = mx_strnew(size);
    int len = size - mx_strlen(res);

    for (int i = 0, j = 0; i < size; i++) {
        hex[i] = ' ';
        if (i == 0)
            hex[i] = ',';
        if (i >= len) {
            hex[i] = res[j];
            j++;
        }
    }
    mx_strdel(&res);
    return hex;
}
