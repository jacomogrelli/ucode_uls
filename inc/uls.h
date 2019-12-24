#ifndef ULS_H
#define ULS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //readlink, isatty
#include <time.h> //ctime, time
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "libmx.h"
//new for uls
#include <dirent.h> //opendir, readdir, closedir
#include <sys/stat.h> //stat, lstat
#include <sys/types.h> //getpwuid, getgrgid, acl_get_file
#include <sys/ioctl.h> //ioctl,

#define FLAGS "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1" // add any flag while realizing

typedef struct s_dirent {
    long d_ino;                 /* номер inode */
    off_t d_off;                /* смещение на dirent */
    unsigned short d_reclen;    /* длина d_name */
    char d_name[256];  /* имя файла (оканчивающееся нулем) */
} t_dirent;

typedef struct s_lstat {
    dev_t st_dev;           //устройство
    ino_t st_ino;           //inode
    mode_t st_mode;         //режим доступа
    nlink_t st_nlink;       //количество жестких ссылок
    uid_t st_uid;           //идентификатор пользователя-владельца
    gid_t st_gid;           //идентификатор группы-владельца
    dev_t st_rdev;          //тип устройства, (если это устройство)
    off_t st_size;          //общий размер в байтах
    blksize_t st_blksize;   //размер блока ввода-вывода, в файловой системе
    blkcnt_t st_blocks;     //количество выделенных блоков
    // time_t        st_atime;    /* время последнего доступа */
    // time_t        st_mtime;    /* время последней модификации */
    // time_t        st_ctime;    /* время последнего изменения */
} t_lstat;

typedef struct s_uls_out {
    t_list *errors; //массив ошибок
    t_list *files; //массив файлов
    t_list *folders; //массив папок
} t_uls_out;


int mx_flag_check(int argc, char **argv, int **flags);
void mx_empty_flag(void);
void mx_error_no_such(char *argv);

#endif
