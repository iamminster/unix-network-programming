//
// Created by nguyen minh on 2020/02/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024 /* make it a 1K shared memory segment */

int main(int argc, char *argv[]) {
    key_t key;
    int shmid;
    char *data;
    int mode;

    key = ftok("shm_demo.c", 'R'); // create key
    shmid = shmget(key, SHM_SIZE, 0644|IPC_CREAT); // create shared memory
    // get pointer points to that shared memory
    data = shmat(shmid, (void *)0, 0);
    // read or write data
    if (argc == 2) {
        // write
        printf("writing to segment: \"%s\"\n", argv[1]);
        strncpy(data, argv[1], SHM_SIZE);
    } else {
        // read
        printf("segment contains\"%s\"\n", data);
    }

    // detach pointer
    shmdt(data);
    // delete shared memory
    return 0;
}