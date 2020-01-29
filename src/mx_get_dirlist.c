#include "uls.h"

void mx_get_dirlist(t_uls_out *all, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    struct stat buf2;


    while (all->folders) {
        dirp = opendir(all->folders);
        while ((buf = readdir(dirp)) != NULL) {
            if (lstat(buf->d_name, &buf2) > 0)
                mx_push_stat(&all->files->dirlist,
                mx_lstat_fill(buf2, buf->d_name));
            // if (MX_ISDIR(buf2.st_mode) && flags[mx_get_char_index(FLAGS, 'R')])
            //     mx_get_dirlist()
            all->files->dirlist = all->files->dirlist->next;
        }
        if (closedir(dirp) < 0)
            exit(-1);
    }
}
