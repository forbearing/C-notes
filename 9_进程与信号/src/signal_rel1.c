/*
 * 文件名: signal_rel1.c
 * 描述: 不可靠信号的介绍
 * 完成日期: 2018年2月16:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void sig_handler(int signo){
	if(signo == SIGINT){
		printf("process the SIGINT\n");
		sleep(5);
		printf("%d catch SIGINT\n", getpid());
		printf("process the SIGINT finished\n");
	}
	if(signo == SIGTSTP){
		printf("process the SIGTSTP\n");
		sleep(5);
		printf("%d catch SIGTSTP\n", getpid());
		printf("process the SIGTSTP finished\n");
	}
}

int main(void)
{
	if(signal(SIGINT, sig_handler) == SIG_ERR){
		perror("signal SIGINT error");
	}
	if(signal(SIGTSTP, sig_handler) == SIG_ERR){
		perror("signal SIGTSTP error");
	}

	printf("begin running\n");
	while(1)	pause();		// 进程暂停等待信号
	printf("end running\n");

	return 0;
}
