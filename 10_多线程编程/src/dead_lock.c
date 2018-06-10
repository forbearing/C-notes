/*
 * 文件名: dead_lock.c
 * 描述: 死锁的实现
 * 完成日期: 2018年2也23日 9:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <errno.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int value;
	pthread_mutex_t mutex;
}ResourceA;

typedef struct{
	int value;
	pthread_mutex_t mutex;
}ResourceB;

typedef struct{
	ResourceA *ra;
	ResourceB *rb;
}Storage;

void* a_fn(void* arg){
	Storage *s = (Storage*)arg;
	pthread_mutex_lock(&s->ra->mutex);
	sleep(1);
	printf("0x%lx is waiting for ResouceB ...\n", pthread_self());
	pthread_mutex_lock(&s->rb->mutex);
	printf("ResourceA value is: %d\n", s->ra->value);
	printf("ResourceB value is: %d\n", s->rb->value);
	pthread_mutex_unlock(&s->ra->mutex);
	pthread_mutex_unlock(&s->rb->mutex);
}

void* b_fn(void* arg){
	Storage *s = (Storage*)arg;
	pthread_mutex_lock(&s->rb->mutex);
	sleep(1);
	printf("0x%lx is waiting for ResourceA ...\n", pthread_self());
	pthread_mutex_lock(&s->ra->mutex);
	printf("ResourceA value is: %d\n", s->ra->value);
	printf("ResourceB value is: %d\n", s->rb->value);
	pthread_mutex_unlock(&s->ra->mutex);
	pthread_mutex_unlock(&s->rb->mutex);
}

int main(void)
{
	ResourceA ra;
	ResourceB rb;
	ra.value = 100;
	rb.value = 200; 
	pthread_mutex_init(&ra.mutex, NULL);
	pthread_mutex_init(&rb.mutex, NULL);
	Storage s = {&ra, &rb};

	int err;
	pthread_t thread_a, thread_b;
	if(pthread_create(&thread_a, NULL, a_fn, (void*)&s) != 0)
		handle_error("pthread_create error");
	if((err = pthread_create(&thread_b, NULL, b_fn, (void*)&s)) != 0){
		fprintf(stderr, "pthread_create: %s\n", strerror(err));
		exit(EXIT_FAILURE);
	}

	pthread_join(thread_a, NULL);
	pthread_join(thread_b, NULL);
	
	pthread_mutex_destroy(&ra.mutex);
	pthread_mutex_destroy(&rb.mutex);

	return 0;
}
