/*
 * 文件名: pthread_cal2.c
 * 描述: 一个线程进行计算, 多个线程获取结果
 * 完成日期: 2018年2月21日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int res;
	int counter;			// 用于统计获取结果线程的数量
	pthread_cond_t cond;	// 条件变量
	pthread_mutex_t mutex;	// 互斥锁
}Result;

void* set_fn(void *arg){
	int i, sum = 0;
	for(; i<=100; i++)
		sum += i;
	Result *r = (Result*)arg;
	r->res = sum;
	pthread_mutex_lock(&r->mutex);
	while(r->counter < 2){
		pthread_mutex_unlock(&r->mutex);
		sleep(1);
		pthread_mutex_lock(&r->mutex);
	}
	pthread_mutex_unlock(&r->mutex);
	pthread_cond_broadcast(&r->cond);
	return (void*)0;
}

void* get_fn(void *arg){
	Result *r = (Result*)arg;
	pthread_mutex_lock(&r->mutex);
	r->counter++;
	pthread_cond_wait(&r->cond, &r->mutex);
	pthread_mutex_unlock(&r->mutex);
	int res = r->res;
	printf("0x%lx get sum is %d\n", pthread_self(), res);
	return (void*)0;
}

int main(void)
{
	pthread_t set, get1, get2;
	Result r;
	r.counter = 0;
	pthread_mutex_init(&r.mutex, NULL);
	pthread_cond_init(&r.cond, NULL);

	if(pthread_create(&set, NULL, set_fn, (void*)&r) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&get1, NULL, get_fn, (void*)&r) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&get2, NULL, get_fn, (void*)&r) != 0)
		handle_error("pthread_create error");

	pthread_join(set, NULL);
	pthread_join(get1, NULL);
	pthread_join(get2, NULL);

	pthread_cond_destroy(&r.cond);
	pthread_mutex_destroy(&r.mutex);

	return 0;
}
