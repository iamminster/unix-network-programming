//
// Created by nguyen minh on 2020/02/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void) {
    key_t key;
    int semid;
    union semun arg;

    if ((key =ftok("sem_demo.c", 'J')) == -1) {
        perror("ftok error");
        exit(1);
    }

    if ((semid = semget(key, 1, 0)) == -1) {
        perror("semget error");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID, arg) == -1) {
        perror("semctl error");
        exit(1);
    }

    return 0;
}