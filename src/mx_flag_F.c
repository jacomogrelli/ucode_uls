#include "uls.h"

void mx_flag_F(t_list *out) {
    DIR *dirp;
    struct dirent *dbuf;
    struct stat buf;
    t_list *lst = NULL;

    if (!(dirp = opendir(out->data)))
        exit(1);
    for (; (dbuf = readdir(dirp));) {
        lstat(dbuf->d_name, &buf);
        if (MX_ISDIR(buf.st_mode))
            mx_push_back(&lst, mx_strcat(dbuf->d_name, "/")); // dirs
        else if (MX_ISEXEC(buf.st_mode))
            mx_push_back(&lst, mx_strcat(dbuf->d_name, "*")); // exec
        else if (MX_ISLNK(buf.st_mode))
            mx_push_back(&lst, mx_strcat(dbuf->d_name, "@")); // links /usr/sbin/
        else if (MX_ISFIFO(buf.st_mode))
            mx_push_back(&lst, mx_strcat(dbuf->d_name, "|")); // if the file is a FIFO
        else if (MX_ISSOCK(buf.st_mode))
            mx_push_back(&lst, mx_strcat(dbuf->d_name, "=")); // if the file is a socket
        else
            mx_push_back(&lst, dbuf->d_name);
    }
    if (closedir(dirp) > 0)
        exit(1);
    mx_ascii_sort_list(lst);
    mx_printlist(lst);
}
