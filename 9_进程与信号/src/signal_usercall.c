/*
 * 文件名: signal_usercall.c
 * 描述: 自定义用户函数被中断可重启
 * 完成日期: 2018年2月12日 19:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
	if(signo == SIGTSTP)
		printf("SIGTSTP occured\n");
}

void call_fun(void){
	printf("begin running call_fun\n");
	sleep(10);
	printf("end running call_fun\n");
}

int main(void)
{
	if(signal(SIGTSTP, sig_handler) == SIG_ERR ){
		perror("signal error");
		exit(EXIT_FAILURE);
	}

	printf("begin running main\n");
	call_fun();
	printf("end runnning main\n");

	return 0;
}
