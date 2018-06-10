/*
 * 文件名: raise_kill.c
 * 描述: raise 和 kill 函数的使用
 * 完成日期: 2018年2月12日 15:30
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

void sig_handler(int signo){
	printf("signal %d catched\n", signo);
}

int main(int argc, char *argv[])
{
	if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		handle_error("signal SIGUSR1 error");
	if(signal(SIGUSR2, sig_handler) == SIG_ERR)
		handle_error("signal SIGUSR1 error");

	raise(SIGUSR1);
	kill(getpid(), SIGUSR2);

	/* kill 函数把自己杀死 */
	int i = 10;
	while(i-- > 0){
		printf("%d out %d\n", getpid(), i);
		sleep(1);
		if(i == 5)
			kill(getpid(), SIGKILL);
			//kill(getpid(), SIGINT);
	}

	return 0;
}
