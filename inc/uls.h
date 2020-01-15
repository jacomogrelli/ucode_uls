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
#include <sys/types.h>
#include <sys/acl.h> //acl_get_file, acl_to_text, acl_free
#include <pwd.h> //getpwuid
#include <grp.h> //getgrgid
#include <sys/ioctl.h> //ioctl
#include <sys/xattr.h> //listxattr, getxattr

#define FLAGS "Aal" // add any flag while realizing

//------macros pack for definition of type------
#define MX_ISBLK(m)      (((m) & S_IFMT) == S_IFBLK)  /* 'b'lock special */
#define MX_ISCHR(m)      (((m) & S_IFMT) == S_IFCHR)  /* 'c'har special */
#define MX_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)  /* 'd'irectory */
#define MX_ISFIFO(m)     (((m) & S_IFMT) == S_IFIFO)  /* 'p'fifo or socket */
#define MX_ISREG(m)      (((m) & S_IFMT) == S_IFREG)  /* '-'regular file */
#define MX_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)  /* 'l'symbolic link */
#define MX_ISSOCK(m)     (((m) & S_IFMT) == S_IFSOCK) /* 's'socket */

//------macros pack for getting major and minor------
#define MX_GETMAJ(x)     ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_GETMIN(x)     ((int32_t)((x) & 0xffffff))

typedef struct s_lstat {
    // dev_t st_dev;           //устройство
    // ino_t st_ino;           //inode
    char *name;             //name of file
    char *path;             //path to file, argv[i]
    char *mode;             //mode_t st_mode, режим доступа
    int nlink;              //количество жестких ссылок
    char *plink;            //"[link path]"
    char *own_name;         //имя пользователя-владельца
    char *group;            // gid_t st_gid, идентификатор группы-владельца
    // dev_t st_rdev;          //тип устройства, (если это устройство)
    char *size_b;   // off_t st_size, общий размер в байтах
    // blksize_t st_blksize;   //размер блока ввода-вывода, в файловой системе
    // blkcnt_t st_blocks;     //количество выделенных блоков
    // time_t        st_atime;    /* время последнего доступа */
    char *mtime;            //time_t st_mtime, время последней модификации
    // time_t        st_ctime;    /* время последнего изменения */
    // struct s_lstat *next;
    struct s_lstat *next;
} t_lstat;

typedef struct s_uls_out {
    t_list *errors; //массив ошибок
    t_list *files; //массив файлов
    t_list *folders; //массив папок
} t_uls_out;

// void mx_basic(int argc, char **argv, int flag_count);
int mx_flag_check(int argc, char **argv, int **flags);
t_list *mx_empty_flag(int *flags);
void mx_error_no_such(char *argv);
t_list *mx_ascii_sort_list(t_list *lst);
t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags);
void mx_free_t_lstat (t_lstat *temp);
int mx_get_winsize(void);

//------Filling any information about file/link/dir pack------
t_lstat *mx_lstat_fill(struct stat buf, char *argv);
char *mx_get_owner(uid_t st_uid);
char *mx_get_group(gid_t st_gid);
char *mx_get_name(char *argv);
char *mx_get_mtime(struct timespec stmtime);
char *mx_get_permission(mode_t st_mode, char *path);
char mx_get_perm_type(mode_t st_mode);
char *mx_get_plink(char *argv, off_t st_size, char p);
char *mx_get_size(struct stat buf);
char mx_get_perm_10(char *path);

//------Output pack
void mx_output_error(t_list *err);
void mx_output_files(t_list *files, int *flags);

#endif
