/*
 * 文件名: pthread_race.c
 * 描述: 线程创建 pthread_create 的使用
 * 完成日期: 2018年2月14日 11:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

/* 定义线程运行函数 */
void* th_fn(void *arg){
	int distance = (int*)arg;
	int i;
	for(i=1; i<= distance; i++){
		printf("%lx run %d\n", pthread_self(), i);
		int time = (int)(drand48() * 100000);
		usleep(time);				// 微秒
	}

	return (void*) 0;
}

int main(void)
{
	int err;
	pthread_t rabbit, turtle;			// 定义线程标识符
	if((err = pthread_create(&rabbit, NULL, th_fn, (void*)50)) != 0)
		handle_error("pthread_create error");
	if((err = pthread_create(&turtle, NULL, th_fn, (void*)50)) != 0)
		handle_error("pthread_create error");

	pthread_join(rabbit, 0);
	pthread_join(turtle, 0);
	printf("control thread id: %lx\n", pthread_self());
	printf("finished\n");

	return 0;
}
