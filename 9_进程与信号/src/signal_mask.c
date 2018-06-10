/*
 * 文件名: signal_mask.c
 * 描述: 信号集函数的使用
 * 完成日期: 2018年2月14日 10:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
//#include <sys/types.h>

void out_set(sigset_t set){
	int i = 1;
	for(; i<=31; i++){
		/* 判断信号屏蔽字的某些位置是否置1 */
		if(sigismember(&set, i))
			printf("%d\n", i);
	}
}

void sig_handler(int signo){
	printf("begin process the %d\n", signo);
	/* 获得正在处理信号时内核中的信号屏蔽字内容 */
	sigset_t oset;
	sigemptyset(&oset);
	if(sigprocmask(SIG_BLOCK, NULL, &oset) < 0){
		perror("sigprocmask error");
	}
	out_set(oset);
	printf("finish process the %d\n", signo);
}

int main(void)
{
	if(signal(SIGUSR1, sig_handler) == SIG_ERR){
		perror("signal SIGUSR1 error");
	}
	if(signal(SIGUSR2, sig_handler) == SIG_ERR){
		perror("signal SIGUSR2 error");
	}

	sigset_t oset;			// 放置内核信号屏蔽字的内容
	printf("before signal occured mask: \n");
	/* 清空信号集 oset */
	sigemptyset(&oset);
	/* 在信号发生之前,获得信号屏蔽字的内容 */
	if(sigprocmask(SIG_BLOCK, NULL, &oset) < 0){
		perror("sigprocmask error");
	}
	/* 打印信号集 */
	out_set(oset);

	printf("process %d wait signal...\n", getpid());
	pause();

	printf("after signal occured mask: \n");
	/* 清空信号集 oset */
	sigemptyset(&oset);
	/* 在信号发生后(处理完毕),获得信号屏蔽字的内容 */
	if(sigprocmask(SIG_BLOCK, NULL, &oset) < 0){
		perror("sigprocmask 2 error");
	}
	out_set(oset);

	return 0;
}
