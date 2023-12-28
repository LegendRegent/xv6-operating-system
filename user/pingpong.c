//
// Created by Kyle Sun on 12/27/23.
//
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int parent_to_child_pipe[2];
    int child_to_parent_pipe[2];
    pipe(parent_to_child_pipe);
    pipe(child_to_parent_pipe);

    int pid = fork();
    if(pid > 0){
        // fork returns the pid of the child process to the parent process.
        // parent
        // close the read end of the parent_to_child_pipe
        close(parent_to_child_pipe[0]);
        // close the write end of the child_to_parent_pipe
        close(child_to_parent_pipe[1]);
        write(parent_to_child_pipe[1], " ", 1);
        if(read(child_to_parent_pipe[0], " ", 1) == 1){
            printf("%d: received pong\n", getpid());
        }

        wait((int *) 0);
        exit(0);

    } else if(pid == 0){
        // child
        // close the write end of the parent_to_child_pipe
        close(parent_to_child_pipe[1]);
        // close the read end of the child_to_parent_pipe
        close(child_to_parent_pipe[0]);

        write(child_to_parent_pipe[1], " ", 1);
        if(read(parent_to_child_pipe[0], " ", 1) == 1){
            printf("%d: received ping\n", getpid());
        }

        exit(0);
    } else {
        fprintf(2,"fork error\n");
    }

    exit(0);
}
