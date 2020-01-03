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
#include <sys/types.h> //acl_get_file
#include <pwd.h> //getpwuid
#include <grp.h> //getgrgid
#include <sys/ioctl.h> //ioctl,

#define FLAGS "ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1" // add any flag while realizing

typedef struct s_lstat {
    // dev_t st_dev;           //устройство
    // ino_t st_ino;           //inode
    // mode_t st_mode;         //режим доступа
    int nlink;       //количество жестких ссылок
    char *own_name; //имя пользователя-владельца
    char *group; // gid_t st_gid, идентификатор группы-владельца
    // dev_t st_rdev;          //тип устройства, (если это устройство)
    unsigned long size_b; // off_t st_size, общий размер в байтах
    // blksize_t st_blksize;   //размер блока ввода-вывода, в файловой системе
    // blkcnt_t st_blocks;     //количество выделенных блоков
    // time_t        st_atime;    /* время последнего доступа */
    char *mtime;//time_t st_mtime, время последней модификации
    // time_t        st_ctime;    /* время последнего изменения */
    struct s_lstat *next;
} t_lstat;

typedef struct s_uls_out {
    t_list *errors; //массив ошибок
    t_list *files; //массив файлов
    t_list *folders; //массив папок
} t_uls_out;

void mx_basic(int argc, char **argv, int flag_count);
int mx_flag_check(int argc, char **argv, int **flags);
void mx_empty_flag(void);
void mx_error_no_such(char *argv);
t_list *mx_ascii_sort_list(t_list *lst);

//------Filling any information about file/link/dir pack------
t_lstat *mx_lstat_fill(struct stat buf);
char *mx_get_owner(uid_t st_uid);
char *mx_get_group(gid_t st_gid);
char *mx_get_mtime(struct timespec stmtime);


#endif
