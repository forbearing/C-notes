/*
 * 文件名: signal_alarm.c
 * 描述: alarm 函数的使用
 * 完成日期: 2018年2月12日 16:00
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){
	if(signo == SIGALRM){
		printf("clock time out\n");
		// 重新设置定时器(周期性的定时)
		alarm(5);
	}
}

void out_data(void){
	int i = 1;
	while(i <= 20){
		double d = drand48();
		printf("%-5d: %lf\n", i++, d);
		if(i == 16)
			alarm(0);			//取消之前设置的定时器
		sleep(1);
	}
}

int main(void)
{
	if(signal(SIGALRM, sig_handler) == SIG_ERR){
		perror("signal SIGALRM error");
	}

	// 设置定时器
	alarm(5);
	printf("  Begin running main\n");
	out_data();
	printf("  End running main\n");

	return 0;
}
