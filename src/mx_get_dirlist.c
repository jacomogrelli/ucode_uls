#include "uls.h"

static t_list *get_subdir(t_list *folders, int *flags);

void mx_get_dirlist(t_uls_out *all, int *flags) {
    // DIR *dirp;
    // struct dirent *buf;
    // struct stat buf2;
    // t_lstat *head = all->dirlist;
    // t_list *head_f = all->folders;
    // if (flags) //временная хуйня, убрать
    all->folders = get_subdir(all->folders, flags);

    // while (head_f) {
    //     dirp = opendir(head_f->data);
    //     // while ((buf = readdir(dirp)) != NULL) {
    //     //     if (lstat(mx_strjoin("libmx/", buf->d_name), &buf2)) {
    //     //         mx_push_stat(&head, mx_lstat_fill(buf2, mx_strjoin("libmx/", buf->d_name)));
    //     //         head = head->next;
    //     //     }
    //     // }
    //     // if (closedir(dirp) < 0)
    //     //     exit(-1);
    //     // head_f = head_f->next;
    // }
}

static t_list *get_subdir(t_list *folders, int *flags) {
    DIR *dirp;
    struct dirent *buf;
    t_list *head = folders;
    struct stat buf2;

    if (!flags[mx_get_char_index(FLAGS, 'R')])
        return folders;
    while (head) {
        dirp = opendir(head->data);
        while ((buf = readdir(dirp)) != NULL) {
            if (mx_strcmp(buf->d_name, ".") != 0
                && mx_strcmp(buf->d_name, "..") != 0) {
                if (lstat(mx_namejoin(head->data, buf->d_name), &buf2) >= 0) {
                    if (MX_ISDIR(buf2.st_mode)) {
                        mx_push_back(&head,
                        mx_namejoin(head->data, buf->d_name));
                    }
                }
            }
        }
        if (closedir(dirp) < 0)
            exit (-1);
        head = head->next;
    }
    mx_printlist(folders);
    return folders;
}
