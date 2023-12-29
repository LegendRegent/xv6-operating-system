//
// Created by Kyle Sun on 12/28/23.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void batch(int *p) {

    // A batch should only have an input pipe[0] to begin with.

    int prime;
    int n;
    int p2[2];

    if (read(p[0], &prime, sizeof(int)) == 0) {
        close(p[0]);
        exit(0);
    }
    printf("prime %d\n", prime);
    pipe(p2);
    if (fork() == 0) {
        close(p2[1]);
        batch(p2);
    } else {
        close(p2[0]);
        while (read(p[0], &n, sizeof(int)) != 0) {
            if (n % prime != 0) {
                write(p2[1], &n, sizeof(int));
            }
        }
        close(p[0]);
        close(p2[1]);
        wait((int *) 0);
        exit(0);
    }
}

int
main(int argc, char *argv[])
{
    int p[2];

    pipe(p);
    if (fork() >0) {
        close(p[0]);
        for (int i = 2; i <= 35; i++) {
            write(p[1], &i, sizeof(int));
        }
        close(p[1]);
        wait((int *) 0);
        exit(0);
    } else {
        close(p[1]);
        batch(p);
    }

    exit(0);
}