#include "uls.h"

char *mx_flag_F(char *name, struct stat buf) {
    if (MX_ISDIR(buf.st_mode))
        name = mx_strjoin(name, "/"); // dirs
    else if (MX_ISLNK(buf.st_mode))
        name = mx_strjoin(name, "@"); // links /usr/sbin/
    else if (MX_ISEXEC(buf.st_mode))
        name = mx_strjoin(name, "*"); // exec
    else if (MX_ISFIFO(buf.st_mode))
        name = mx_strjoin(name, "|"); // if the file is a FIFO
    else if (MX_ISSOCK(buf.st_mode))
        name = mx_strjoin(name, "="); // if the file is a socket
    return name;
}
