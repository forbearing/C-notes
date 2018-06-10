/*
 * 文件名: signal_rel2.c
 * 描述: 不可靠信号问题
 * 完成日期: 2018年2月12日 20:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int is_sig_occ = 0;

void sig_handler(int signo){
	printf("signo occured: %d\n", signo);
	is_sig_occ = 1;
	printf("I will running\n");
}

int main(void)
{
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		perror("signal SIGINT error");
	
	printf("begin running\n");
	while(is_sig_occ == 0){
		sleep(5);
		pause();		// 等待信号发生
	}

	/* 下列代码是依赖依赖于信号的 */
	//printf("I will running\n");

	return 0;
}
