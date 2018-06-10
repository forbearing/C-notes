/*
 * 文件名: process_orphen.c
 * 描述: 创建孤儿进程, 孤儿进程的父进程是 1号 进程
 * 完成日期: 2018年2月8日18:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid > 0){
		printf("%d deaded\n", getpid());
		exit(0);
	}else{
		sleep(4);
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
	}

	return 0;
}
