/*
 * 文件名: signal_pending.c
 * 描述:
 * 完成日期: 2018年2月14日: 10:15
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void out_set(sigset_t set){
	int i = 1;
	for(; i<=31; i++){
		if(sigismember(&set, i)){
			printf("%d", i);
		}
	}
	printf("\n");
}

void sig_handler(int signo){
	printf("begin the signal handler\n");
	int i = 0;
	sigset_t set;
	for(; i<20; i++){
		sigemptyset(&set);
		if(sigpending(&set) < 0){
			perror("sigpending error");
		}else{
			printf("pending signal: ");
			out_set(set);
			sigemptyset(&set);
		}
		printf("i is %d\n", i);
		sleep(1);
	}
	printf("end the signal handler\n");

}

int main(void)
{
	if(signal(SIGTSTP, sig_handler) == SIG_ERR){
		perror("signal SIGTSTP error");
	}

	printf("process %d wait signal...\n", getpid());
	pause();		// 进程暂停等待信号
	printf("process finished\n");

	return 0;
}
