#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	char *s = "hello linux";
	ssize_t size = strlen(s) * sizeof(char);
	
	FILE *fp = fopen("fp", "w");
	if(fp == NULL)
		handle_error("fopen error");
	int fd = open("fd", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
	if(fd < 0)
		handle_error("open error");

	/* 只有父进程执行 */
	fprintf(fp, "s:%s pid:%d\n", s, getpid());
	write(fd, s, size);

	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){
		printf("parent process\n");
	}else{
		printf("child process\n");
	}

	/* 父进程和子进程都执行 */
	fprintf(fp, "hello python\n");

	fclose(fp);
	close(fd);

	return 0;
}
