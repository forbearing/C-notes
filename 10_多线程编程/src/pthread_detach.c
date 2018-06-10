/*
 * 文件名: pthread_detach.c
 * 描述: 线程分离属性的使用
 * 完成日期: 2018年2月15日
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

void out_state(pthread_attr_t *attr){
	int state;
	if(pthread_attr_getdetachstate(attr, &state) != 0){
		perror("getdetachstate error");
	}else{
		if(state == PTHREAD_CREATE_JOINABLE)
			printf("joinalbe state\n");
		else if(state == PTHREAD_CREATE_DETACHED)
			printf("detached state\n");
		else
			printf("error state\n");
	}
}

void* th_fn(void* arg){
	int i;
	int sum = 0;
	for(i=1; i<=100; i++)
		sum +=i;
	return (void*)sum;
}

int main(void)
{
	pthread_t default_th, detach_th;
	pthread_attr_t attr;					// 定义线程属性

	pthread_attr_init(&attr);				// 对线程属性进行初始化
	out_state(&attr);						// 输出分离属性
	/* 以分离属性的默认值正常启动 */
	if(pthread_create(&default_th, &attr, th_fn, (void*)0) != 0)
		handle_error("pthread_create error");
	int res;
	if(pthread_join(default_th,(void*)&res) != 0)
		handle_error("pthread_join error");
	else
		printf("default return is %d\n", res);
	printf("------------------------------------------\n");

	/* 设置分离属性为分离状态 */
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	out_state(&attr);
	if(pthread_create(&detach_th, &attr, th_fn, (void*)0) != 0)
		handle_error("pthread_create error");
	if(pthread_join(detach_th, (void*)&res) != 0)
		handle_error("pthread_join error");
	else
		printf("default return is %d\n", res);

	/* 销毁线程属性 */
	pthread_attr_destroy(&attr);
	printf("0x%lx finished\n", pthread_self());
	sleep(1);

	return 0;
}
