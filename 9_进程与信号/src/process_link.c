/*
 * 文件名: process_link.c
 * 描述: 创建进程链
 * 完成日期: 2018年2月8日:18:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int counter = 0;
	if(argc < 2)
		counter = 2;
	else
		counter = atoi(argv[1]);

	int i = 1;
	pid_t pid;
	for(; i<counter; i++){
		pid = fork();
		if(pid < 0){
			perror("fork error");
			exit(EXIT_FAILURE);
		}else if(pid > 0)	break;
			/* 父进程退出循环, 子进程继续循环 */
	}
	printf("pid: %d ppid: %d\n", getpid(), getppid());
	while(1)
		sleep(1);

	return 0;
}
