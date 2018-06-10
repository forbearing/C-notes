/*
 * 文件名: pthread_alarm.c
 * 描述: alarm 信号是进程资源而不是线程资源, 
 *		子线程调用 alarm, alarm 信号是发送给主控线程而不是子线程
 * 完成日期: 2018年2月23日 10:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

void sig_handler(int signo){
	printf("pthread id in the sig_handler: %lx\n", pthread_self());
	if(signo == SIGALRM)
		printf("timeout ....\n");
	alarm(2);
}

void* th_fn(void* arg){
	if(signal(SIGALRM, sig_handler) == SIG_ERR)
		handle_error("signal error");
	alarm(2);
	int i;
	for(i=1; i<=100; i++){
		printf("(%lx) i: %d\n", pthread_self(), i);
		sleep(1);
	}
	return (void*)0;
}

int main(void)
{
	pthread_t th;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	if(pthread_create(&th, &attr, th_fn, NULL) != 0)
		handle_error("pthread_create error");

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGALRM);
	pthread_sigmask(SIG_SETMASK, &set, NULL);

	while(1){
		printf("control thread(%lx) is running\n", pthread_self());
		sleep(10);
	}
	printf("control thread over\n");

	pthread_attr_destroy(&attr);

	return 0;
}
