/*
 * 文件名: pthread_race2.c
 * 描述: 线程创建
 * 完成日期: 2018年2月14日: 15:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0);

typedef struct{
	char name[20];
	int time;
	int start;
	int end;
}RaceArg;


void * th_fn(void *arg){
	RaceArg *r = (RaceArg*)arg;
	int i = r->start;
	for(; i<=r->end; i++){
		printf("%s(%lx) running %d\n", r->name, pthread_self(), i);
		usleep(r->time);
	}
	//return (void*)0;
	return (void*)(r->end - r->start);
}

int main(void)
{
	int err;
	pthread_t rabbit, turtle;
	RaceArg r_a = {"rabbit", (int)(drand48()*100000000), 20, 50};
	RaceArg t_a = {"turtle", (int)(drand48()*100000000), 10, 60};
	
	if((err = pthread_create(&rabbit, NULL, th_fn, (void*)&r_a)) != 0)
		handle_error("pthread_create error");
	if((err = pthread_create(&turtle, NULL, th_fn, (void*)&t_a)) != 0)
		handle_error("pthread_create error");
	
	int *result1;
	pthread_join(rabbit, (void**)&result1);
	printf("rabbit distance is %d\n", (int)result1);
	int result2;
	pthread_join(turtle, (void*)&result2);
	printf("turtle distance is %d\n", result2);

	printf("control thread id: %lx\n", pthread_self());
	printf("finished\n");

	return 0;
}
