/*
 * 文件名: pthread_cal.c
 * 描述: 一个线程计算,另一个线程阻塞等待第一个线程计算, 第一个线程计算完毕通知
 *		另一个线程取计算结果
 * 完成日期: 2018年2月19日: 8:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int res;
	int is_wait;				// 用户给出的用于判断的条件
	pthread_cond_t cond;		// 条件变量
	pthread_mutex_t mutex;		// 互斥锁
}Result;

/* 计算并将结果放入 Result 中的线程运行函数 */
void * set_fn(void *arg){
	int i = 1, sum = 0;
	for(; i<=100; i++)
		sum += i;
	Result *r = (Result*)arg;
	r->res = sum;
	pthread_mutex_lock(&r->mutex);
	while(!r->is_wait){			// 判断获取结果的线程是否准备好
		pthread_mutex_unlock(&r->mutex);
		sleep(1);
		pthread_mutex_lock(&r->mutex);
	}
	pthread_cond_broadcast(&r->cond);
	return (void*)0;
}
/* 获取结果的线程运行函数 */
void * get_fn(void *arg){
	Result *r = (Result*)arg;
	pthread_mutex_lock(&r->mutex);
	r->is_wait = 1;				// 代表获取结果的线程已经准备好
	pthread_cond_wait(&r->cond, &r->mutex); 
	pthread_mutex_unlock(&r->mutex);	// 唤醒后
	int res = r->res;
	printf("0x%lx get sum is %d\n", pthread_self(), res);
	return (void*)0;
}

int main(void)
{
	pthread_t set, get;
	Result r;
	r.is_wait = 0;
	pthread_cond_init(&r.cond, NULL);
	pthread_mutex_init(&r.mutex, NULL);

	if(pthread_create(&set, NULL, set_fn, (void*)&r) != 0)	// 计算结果线程
		handle_error("pthread_create error");
	if(pthread_create(&get, NULL, get_fn, (void*)&r) != 0)	// 获取结果线程
		handle_error("pthread_create error");

	pthread_join(set, NULL);
	pthread_join(get, NULL);

	pthread_cond_destroy(&r.cond);
	pthread_mutex_destroy(&r.mutex);

	return 0;
}
