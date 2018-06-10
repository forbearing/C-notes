/*
 * 文件名: sem_test.c
 * 描述: 信号量的使用
 * 完成日期: 2018年2月22日: 21:40
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

sem_t sem1, sem2;

void* a_fn(void* arg){
	sem_wait(&sem1);
	printf("thread A running\n");
	return (void*)0;
}

void* b_fn(void* arg){
	sem_wait(&sem2);
	printf("thread B running\n");
	sem_post(&sem1);		// 释放线程a
	return (void*)0;
}

void* c_fn(void* arg){
	printf("thread C running\n");
	sem_post(&sem2);		// 释放线程b
	return (void*)0;
}

int main(void)
{
	pthread_t a, b, c;
	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 0);

	if(pthread_create(&a, NULL, a_fn, (void*)0) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&b, NULL, b_fn, (void*)0) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&c, NULL, c_fn, NULL) != 0)
		handle_error("pthread_create error");

	pthread_join(a, NULL);
	pthread_join(b, NULL);
	pthread_join(c, NULL);

	sem_destroy(&sem1);
	sem_destroy(&sem2);

	return 0;
}
