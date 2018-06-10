/*
 * 文件名: process_fan.c
 * 描述: 创建进程扇
 * 完成日期: 2018年2月8日 18:40
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

	pid_t pid;
	int i = 1;
	for(; i<counter; i++){
		if((pid = fork()) < 0){
			perror("fork error");
			exit(EXIT_FAILURE);
		}else if(pid == 0)	break;
		/* 子进程退出循环, 父进程继续做循环 */
	}

	printf("pid:%d ppid:%d\n", getpid(), getppid());
	while(1)
		sleep(1);

	return 0;
}
