#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_BUF_SIZE 80

void exit_with_failure(char *message) {
	perror(message);
	exit(EXIT_FAILURE);
}


int main(void) {
	int n;
	int pipe_fd[2];
	pid_t pid;
	char msg [] = "hello from parent\n";

	if (pipe(pipe_fd) < 0)
		exit_with_failure("pipe error");
	if ((pid = fork()) < 0) {
		exit_with_failure("fork error");
	} else if (pid > 0) {
		// in parent, closing read end of pipe
		close(pipe_fd[0]);
		write(pipe_fd[1], msg, strlen(msg));
	} else {
		// in child, closing write end of pipe
		close(pipe_fd[1]);
		char line[READ_BUF_SIZE];
		n = read(pipe_fd[0], line, READ_BUF_SIZE);
		write(STDOUT_FILENO, line, n);
	}
	exit(EXIT_SUCCESS);
}
