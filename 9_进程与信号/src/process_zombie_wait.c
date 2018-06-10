/*
 * 文件名: process_zombie.c
 * 描述: 创建僵尸进程
 * 完成日期: 2018年2月8日:19:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
		/* 子进程结束成为僵尸进程 */
		exit(0);
	}else{
		wait(0);
	}

	return 0;
}
