/*
 * 文件名: process_fork3.c
 * 描述: 子进程的继承: 共享数据段,堆,栈. 代码段(正文段)为同一个
 * 完成日期: 2018年2月8日:11:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_v = 30;

int main(void)
{
	int a_v =30;
	static int s_v = 30;

	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid > 0){
		printf("parent process\n");
		g_v = 40;
		a_v = 40;
		s_v = 40;
		printf("\tg_v:%p, a_v:%p, s_v:%p\n", &g_v, &a_v, &s_v);
	}else{
		printf("child process\n");
		g_v = 50;
		a_v = 50;
		s_v = 50;
		printf("\tg_v:%p, a_v:%p, s_v:%p\n", &g_v, &a_v, &s_v);
	}
	printf("\tpid: %d, g_v:%d, a_v:%d, s_v:%d\n", getpid(), g_v, a_v, s_v);

	return 0;
}
