/*
 * 文件名: process_fork2.c
 * 描述: fork 函数的使用, 父进程子进程的运行顺序
 * 完成日期: 2018年2月8日10:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <unistd.h>

int main(void)
{
	printf("current pid: %d\n", getpid());
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
	}else if(pid > 0){
		int i;
		for(i=0; i<10; i++){
			printf("parent: %d\n", getpid());
			sleep(1);
		}
	}else{
		int i;
		for(i=0; i<10; i++){
			printf("child: %d\n", getpid());
			sleep(1);
		}
	}

	return 0;
}
