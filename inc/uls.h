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
#include <errno.h>
#include "libmx.h"
#include <dirent.h> //opendir, readdir, closedir
#include <sys/stat.h> //stat, lstat
#include <sys/types.h>
#include <sys/acl.h> //acl_get_file, acl_to_text, acl_free
#include <pwd.h> //getpwuid
#include <grp.h> //getgrgid
#include <sys/ioctl.h> //ioctl
#include <sys/xattr.h> //listxattr, getxattr

#define FLAGS "AFGRSldmortu1" // add any flag while realizing

// Флаги формата вывода
// -A - almost all - выдавать все файлы, включая скрытые, кроме `.' и `..'
// -F - добавлять к каждому имени файла символ, показывающий его тип
// -G - разноцветный вывод
// -R - рекурсивный вывод всего содержимого
// -l - long output
// -o - long output без группы, отменяет -l
// -d - отменяет открытие каталогов, каталог показывается как файл
// -u - использовать время последнего доступа к файлу
//      вместо времени последней модификации файла.
// -1 - вывод в одноколоночном формате
// -t — сортировать по показываемому временному штампу.
// -S - сортировать по размеру
// -r - сортировка в обратном порядке

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
    char *name;             //name of file
    char *path;             //path to file, argv[i]
    char *mode;             //mode_t st_mode, режим доступа
    int nlink;              //количество жестких ссылок
    char *plink;            //"[link path]"
    char *own_name;         //имя пользователя-владельца
    char *group;            // gid_t st_gid, идентификатор группы-владельца
    char *size_b;           // off_t st_size, общий размер в байтах
    int total;              //количество выделенных блоков
    char *mtime;            //time_t st_mtime, время последней модификации
    time_t st_time;         //время для сортировки
    time_t st_time_nsec;    //время для сортировки
    off_t st_size;          //размер для сортировки
    struct s_lstat *next;
} t_lstat;

typedef struct s_uls_out {
    bool err;       //флаг для возврата 1 в случае нахождения любых ошибок
    t_list *E;      //список ошибок
    t_lstat *F;     //массив файлов
    t_list *D;      //список папок
    t_lstat *Dlist; //массив файлов в папках
    struct s_uls_out *next;
} t_uls_out;

//------parth pack------
int mx_flag_check(int argc, char **argv, int **flags);
t_uls_out *mx_get_args(int argc, int flag, char **argv, int *flags);
t_uls_out *mx_t_uls_out_init(t_uls_out *all);
void mx_push_dir(t_list **list, void *data);
t_list *mx_R(t_list *D, int *flags);
void mx_uls_cleaner(t_uls_out *all);


//------sort pack------
t_uls_out *mx_sorty(t_uls_out *all, int *flags);
void mx_sort_dirs(t_list *dirs, int *flags);
void mx_sort_dirs_size(t_list *dirs, int *flags);
void mx_sort_dirs_ascii(t_list *lst, int *flags);
void mx_sort_dirs_time(t_list *dirs, int *flags);
void mx_sort_dirs_utime(t_list *dirs, int *flags);
void mx_sort_files(t_lstat *files, int *flags);
void mx_sort_files_size(t_lstat *files, int *flags);
void mx_sort_files_time(t_lstat *files, int *flags);
void mx_sort_files_ascii(t_lstat *files, int *flags);
void mx_data_swap(t_lstat *s1, t_lstat *s2);
void mx_char_swap(char **s1, char **s2);
void mx_int_swap(int *i1, int *i2);
void mx_time_swap(time_t *i1, time_t *i2);
void mx_size_swap(off_t *i1, off_t *i2);
t_list *mx_ascii_sort_list(t_list *lst);

//------filling any information about file/link/dir pack------
t_uls_out *mx_get_dirlist(t_uls_out *all, int *flags);
char *mx_namejoin(char *name1, char *name2);
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
void mx_push_stat(t_lstat **list, void *data);
char *mx_flag_F(char *name, struct stat buf);


//------output pack------
int mx_get_winsize(void);
void mx_output_error(t_list *err);
void mx_output_files(t_lstat *out, int *flags);
void mx_output_folders(t_uls_out *all, int *flags, int ac, int flag);
void mx_output_total(t_lstat *Dlist);
void mx_error_no_such(char *argv);
void mx_error_pd(char *argv);
void mx_cat_out(t_lstat *F);
void mx_1_out(t_lstat *F);
void mx_multicol_out(t_lstat *F);
int mx_get_num_files(t_lstat *F);
void mx_def_space(t_lstat *F, int max, int j);
char *mx_struct_index(t_lstat *F, int i);
void mx_long_out(t_lstat *F, int *flags);
void mx_slong_out(t_lstat *F, int *flags, int max_size, int max_gr);
void mx_space(int count);
int mx_get_max_group(t_lstat *F);
void mx_flong_out(t_lstat *F, int max_links, int max_own);
int mx_get_max_size(t_lstat *N);
void mx_print_nonprint_str(const char *s);
void mx_print_dname(char *dname);
void mx_m_out(t_lstat *F);

#endif
