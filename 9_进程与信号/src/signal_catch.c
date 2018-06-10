/*
 * 文件名: signal_catch.c
 * 描述: signal 函数的使用
 * 完成日期: 2018年2月12日 14:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* 定义信号处理函数 */
void sig_handler(int signo){
	printf("%d %d occure\n", getpid(), signo);
}

int main(void)
{
	/* 向内核登记信号处理函数及信号值 */
	if(signal(SIGTSTP, SIG_DFL) == SIG_ERR){
		perror("signal SIGTSTP error");
	}
	if(signal(SIGINT, SIG_DFL) == SIG_ERR){	// SIGINT 默认 是终止进程
		perror("signal SIGINT error");
	}

	/* 不能对 SIGKILL, SIGSTOP 进行信号处理 */
	if(signal(SIGKILL, SIG_IGN) == SIG_ERR){
		perror("signal SIGKILL error");
	}

	if(signal(SIGSTOP, SIG_DFL) == SIG_ERR){
		perror("signal SIGSTOP error");
	}

	int i = 0;
	while(i<10){
		printf("%d out %d\n", getpid(), i++);
		sleep(1);
	}

	return 0;
}
