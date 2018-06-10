/*
 * 文件名: reader_writer.c
 * 描述: 读者写者问题
 *		写者吸入数据, 通知读者读取数据
 *		读者读完数据, 通知写者继续写入数据
 *		依此循环
 * 完成日期: 2018年2月21日 15:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int value;
	pthread_cond_t rc;
	pthread_mutex_t rm;
	int r_wait;
	pthread_cond_t wc;
	pthread_mutex_t wm;
	int w_wait;
}Storage;

void* set_data(Storage *s, int value){
	s->value = value;
}

int get_data(Storage *s){
	return s->value;
}

void* set_fn(void *arg){			// 写者线程执行的线程运行函数
	Storage *s = (Storage*)arg;
	int i = 1;
	for(; i<=100; i++){
		set_data(s, i+100);
		printf("0x%lx(%-5d) write data: %d\n", pthread_self(), i, i+100);
		pthread_mutex_lock(&s->rm);
		while(!s->r_wait){
			pthread_mutex_unlock(&s->rm);
			sleep(1);
			pthread_mutex_lock(&s->rm); 
		}
		s->r_wait = 0;
		pthread_mutex_unlock(&s->rm);
		pthread_cond_broadcast(&s->rc);
		/* 写者线程等待阻塞, 等待读者线程读取完数据后通知唤醒它继续写 */
		pthread_mutex_lock(&s->wm);
		s->w_wait = 1;
		pthread_cond_wait(&s->wc, &s->wm);
		pthread_mutex_unlock(&s->wm);
	}
	return (void*)0;
}

void* get_fn(void *arg){			// 读者线程执行的线程运行函数
	Storage *s = (Storage*)arg;
	int i = 1;
	for(; i<=100; i++){
		pthread_mutex_lock(&s->rm);
		s->r_wait = 1;
		pthread_cond_wait(&s->rc, &s->rm);
		pthread_mutex_unlock(&s->rm);
		int value = get_data(s);
		printf("0x%lx(%-5d) read data: %d\n", pthread_self(), i, value);
		/* 判断写者线程是否准备号 */
		pthread_mutex_lock(&s->wm);
		while(!s->w_wait){
			pthread_mutex_unlock(&s->wm);
			sleep(1);
			pthread_mutex_lock(&s->wm);
		}
		s->w_wait = 0;
		pthread_mutex_unlock(&s->wm);
		pthread_cond_broadcast(&s->wc);
	}
	return (void *)0;
}

int main(void)
{
	pthread_t rth, wth;
	Storage s;
	s.r_wait = 0;
	s.w_wait = 0;
	pthread_mutex_init(&s.rm, NULL);
	pthread_mutex_init(&s.wm, NULL);
	pthread_cond_init(&s.rc, NULL);
	pthread_cond_init(&s.wc, NULL);

	if(pthread_create(&rth, NULL, get_fn, (void*)&s) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&wth, NULL, set_fn, (void*)&s) != 0)
		handle_error("pthread_create error");

	pthread_join(rth, NULL);
	pthread_join(wth, NULL);


	pthread_mutex_destroy(&s.rm);
	pthread_mutex_destroy(&s.wm);
	pthread_cond_destroy(&s.rc);
	pthread_cond_destroy(&s.wc);

	return 0;
}
