//
// Created by nguyen minh on 2020/02/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = 0;
    fl.l_len = 0;
    fl.l_pid = getpid();
    int fd;

    if (argc > 1) {
        printf("acquiring read lock");
        fl.l_type = F_RDLCK;
    }
    else {
        printf("acquiring write lock");

    }

    if ((fd = open("lock_demo.c", O_RDWR)) == -1) {
        perror("open error");
        exit(1);
    }

    printf("Press <ENTER> to try to get lock: ");
    getchar();
    printf("Trying to get lock...");

    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl error");
        exit(1);
    }

    printf("got lock\n");
    printf("Press <ENTER> to release lock: ");
    getchar();

    fl.l_type = F_UNLCK;
    if (fcntl(fd, F_UNLCK, &fl) == -1) {
        perror("fnctl unlock error");
        exit(1);
    }

    printf("Unlocked.\n");
    close(fd);
    return 0;
}