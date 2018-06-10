/*
 * 文件名: pthread_detach_my.c
 * 描述: 线程分离属性的使用
 * 完成日期: 2018年2月15日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

void clean_fn(void* arg){
	printf("clean function is run: %s\n", (char*)arg);
}

void out_state(pthread_attr_t *attr){
	int state;
	if(pthread_attr_getdetachstate(attr, &state) != 0){
		perror("pthread_attr_getdetachstate error");
	}else{
		if(state == PTHREAD_CREATE_JOINABLE)
			printf("joinable state\n");
		else if(state == PTHREAD_CREATE_DETACHED)
			printf("detached state\n");
		else
			printf("Unknow state\n");
	}
}

void* th_fn(void *arg){
	int execute = (int)arg;
	pthread_cleanup_push(clean_fn, "first run");
	pthread_cleanup_push(clean_fn, "second run");
	pthread_cleanup_pop(execute);
	pthread_cleanup_pop(execute);
	
	return (void*)0;
}

int main(void)
{
	pthread_t default_th, detach_th;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	/* 创建分离属性为默认值的线程 */
	if(pthread_create(&default_th, &attr, th_fn, (void*)1) != 0)
		handle_error("pthread_create error");
	out_state(&attr);
	pthread_join(default_th, NULL);

	/* 创建分离属性为分离状态的线程 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&detach_th, &attr, th_fn, (void*)1) != 0)
		handle_error("pthread_create error");
	out_state(&attr);
/*	int err;
	if((err=pthread_join(detach_th, NULL)) != 0)
		fprintf(stderr, "%s\n",strerror(err));	
*/
	pthread_attr_destroy(&attr);
	return 0;
}
