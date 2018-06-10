/*
 * 文件名: pthread_clean.c
 * 描述: 线程清理函数的使用
 * 完成日期: 2018年2月14日 17:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0);

/* 定义线程清理函数 */
void clean_fn(void *arg){
	char *s = (char *)arg;
	printf("clean_fn: %s\n", s);
}

void* th_fn(void *arg){
	int execute = (int)arg;
	pthread_cleanup_push(clean_fn, "first clean func");
	pthread_cleanup_push(clean_fn, "second clean func");
	printf("thread running %lx\n", pthread_self());
	pthread_cleanup_pop(execute);
	pthread_cleanup_pop(execute);
	return (void*)0;
}

int main(void)
{
	pthread_t th1, th2;
	if(pthread_create(&th1, NULL, th_fn, (void*)1) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&th2, NULL, th_fn, (void*)1) != 0)
		handle_error("pthread_create error");

	pthread_join(th1, NULL);
	printf("th(%lx) finished\n", pthread_self());
	pthread_join(th2, NULL);
	printf("th(%lx) finished\n", th2);

	return 0;
}
