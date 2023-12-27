//
// Created by Kyle Sun on 12/27/23.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int i;

    if(argc < 2){
        fprintf(2, "Usage: sleep time...\n");
        exit(1);
    }

    int n = atoi(argv[i]);

    //what is the return value of sleep?
    int test = sleep(n);
    // delete this afterwards
    fprintf(1, "sleep return value: %d\n", test);

    exit(0);
}
