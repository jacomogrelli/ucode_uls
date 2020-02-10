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

#define FLAGS "AFRldou1" // add any flag while realizing

// Флаги формата вывода
// -A - almost all - выдавать все файлы, включая скрытые, кроме `.' и `..'
// -l - long output
// -o - long output без группы, отменяет -l
// -R - рекурсивный вывод всего содержимого
// -F - добавлять к каждому имени файла символ, показывающий его тип
// -1 - вывод в одноколоночном формате
// -d - отменяет открытие каталогов, каталог показывается как файл
// -u - использовать время последнего доступа к файлу
//      вместо времени последней модификации файла.

// Флаги сортировки
// -t — сортировать по показываемому временному штампу.

//------macros pack for definition of type------
#define MX_ISBLK(m)      (((m) & S_IFMT) == S_IFBLK)  /* 'b'lock special */
#define MX_ISCHR(m)      (((m) & S_IFMT) == S_IFCHR)  /* 'c'har special */
#define MX_ISDIR(m)      (((m) & S_IFMT) == S_IFDIR)  /* 'd'irectory */
#define MX_ISFIFO(m)     (((m) & S_IFMT) == S_IFIFO)  /* 'p'fifo or socket */
#define MX_ISREG(m)      (((m) & S_IFMT) == S_IFREG)  /* '-'regular file */
#define MX_ISLNK(m)      (((m) & S_IFMT) == S_IFLNK)  /* 'l'symbolic link */
#define MX_ISSOCK(m)     (((m) & S_IFMT) == S_IFSOCK) /* 's'socket */
#define MX_ISEXEC(mode) ((mode) & S_IXUSR) // for exec files
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
    int total;     //количество выделенных блоков
    // char *atime;    /* время последнего доступа */
    char *mtime;            //time_t st_mtime, время последней модификации
    // time_t        st_ctime;    /* время последнего изменения */
    // struct s_lstat *next;
    struct s_lstat *next;
} t_lstat;

typedef struct s_uls_out {
    t_list *E; //массив ошибок
    t_lstat *F; //массив файлов
    t_list *D; //массив папок
    t_lstat *Dlist;
    struct s_uls_out *next;
} t_uls_out;

int mx_flag_check(int argc, char **argv, int **flags);
t_list *mx_empty_flag(int *flags, char *dir);
void mx_error_no_such(char *argv);
t_list *mx_ascii_sort_list(t_list *lst);
t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags);
void mx_free_t_lstat (t_lstat *temp);
int mx_get_winsize(void);
char *mx_namejoin(char *name1, char *name2);
t_uls_out *mx_t_uls_out_init(t_uls_out *all);

//------Filling any information about file/link/dir pack------
t_lstat *mx_lstat_fill(struct stat buf, char *argv, int *flags, bool r);
char *mx_get_owner(uid_t st_uid);
char *mx_get_group(gid_t st_gid);
char *mx_get_name(char *argv, int *flags, struct stat buf, bool r);
char *mx_get_mtime(struct stat buf, int *flags);
char *mx_get_permission(mode_t st_mode, char *path);
char mx_get_perm_type(mode_t st_mode);
char *mx_get_plink(char *argv, off_t st_size, char p);
char *mx_get_size(struct stat buf);
char mx_get_perm_10(char *path);
int mx_get_total(struct stat buf);
t_uls_out *mx_get_dirlist(t_uls_out *all, int *flags);


//------Output pack------
void mx_output_error(t_list *err);
void mx_output_files(t_lstat *out, int *flags);
void mx_push_stat(t_lstat **list, void *data);
// void mx_output_folders(t_list *out, int *flags);
void mx_output_folders(t_uls_out *all, int *flags, int ac, int flag);
void mx_output_total(t_lstat *Dlist);

// utils
void mx_default_l(t_lstat *o);
void mx_print_l(t_list *D, int *flags);
char *mx_flag_F(char *name, struct stat buf);
t_list *mx_R(t_list *D, int *flags);
t_uls_out *mx_sorty(t_uls_out *all, int *flags);
void mx_uls_cleaner(t_uls_out *all);

// new files from ailchuk branch
void mx_cat_out(t_lstat *F); // Done!
void mx_1_out(t_lstat *F); // Done!
void mx_multicol_out(t_lstat *F); // Done!
int mx_get_num_files(t_lstat *F); // util for mx_multicol_out
void mx_def_space(t_lstat *F, int max, int j); // util for mx_multicol_out
char *mx_struct_index(t_lstat *F, int i); // util for mx_multicol_out
void mx_long_out(t_lstat *F, int *flags); // -l
void mx_slong_out(t_lstat *F, int *flags, int max_size, int max_gr); // for mx_long out
void mx_space(int count); // util for slong_out
int mx_get_max_group(t_lstat *F); // util for slong_out
void mx_flong_out(t_lstat *F); //  for mx_long out
int mx_get_max_size(t_lstat *N); // for mx_long_out
void mx_print_nonprint_str(const char *s);
// --------------- output dirs
void mx_print_dname(char *dname);

#endif
