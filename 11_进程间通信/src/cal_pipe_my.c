#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	int fd[2];
	if(pipe(fd) < 0)
		handle_error("pipe error");

	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){
		close(fd[0]);
		int start = 1, end = 100;
		if(write(fd[1], &start, sizeof(int)) != sizeof(int))
			handle_error("write error");
		if(write(fd[1], &end, sizeof(int)) != sizeof(int))
			handle_error("write error");
		close(fd[1]);
		wait(0);
	}else{
		close(fd[1]);
		int start = 0, end = 0;
		if(read(fd[0], &start, sizeof(int)) < 0)
			handle_error("read error");
		if(read(fd[0], &end, sizeof(int)) < 0)
			handle_error("read error");
		close(fd[0]);
		printf("start: %d, end:%d\n", start, end);
	}

	return 0;
}
