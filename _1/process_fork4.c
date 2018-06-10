/*
 * 文件名: process_fork.c
 * 描述: 父子进程以两种方式操作文件(标准IO, 系统调用)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	char *s = "hello linux";
	ssize_t size = strlen(s) * sizeof(char);

	FILE *fp = fopen("fp", "w");
	if(fp = NULL)
		handle_error("fopen error");
	int fd = open("fd", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
	if(fd < 0)
		handle_error("open error");

	fprintf(fp, "s:%s, pid:%d", s, getpid());
	write(fd, s, size);

	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid > 0){
		printf("parent process\n");
	}else{
		printf("child process\n");
	}

	//fprintf(fp,"hello python\n");



	return 0;
}
