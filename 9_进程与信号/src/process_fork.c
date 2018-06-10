/*
 * 文件名: process_fork.c
 * 描述: fork 函数的使用
 * 完成日期: 2018年2月8日10:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	printf("pid: %d\n\n", getpid());
	/* 创建子进程 */
	pid_t pid = fork();

	/* 在 fork 之后会运行两个进程(父进程和子进程) */
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid > 0){				// 父进程(父进程中, fork 返回的是子进程的ID)
		/* 父进程执行的代码 */
		printf("parent process\n");
		printf("\tmy child pid is: %d\n", pid);
		printf("\tpid is: %d\n", getpid());
		printf("\tppid is: %d\n\n", getppid());
	}else{							// 子进程(子进程中, fork 返回的是0)
		/* 子进程执行的代码 */
		printf("child process\n");
		printf("\tpid is: %d\n", getpid());
		printf("\tppid is: %d\n", getppid());
	}


	return 0;
}
