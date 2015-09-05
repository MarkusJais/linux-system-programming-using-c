#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>  // necessary to compile with -std=c11, otherwise pid_t is not found by gcc

// basic example showing fork(), getpid() and getppid()
int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if(pid > 0) {
        printf("In parent process with pid:%d\n", getpid());
    } else if (pid == 0) {
        printf("In child process with pid:%d and parent pid:%d\n", getpid(), getppid());
    } else {
        printf("fork() failed!");
        return -1;
    }
    return 0;
}
