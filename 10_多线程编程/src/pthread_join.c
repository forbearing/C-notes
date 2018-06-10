/*
 * 文件名: pthread_join.c
 * 描述: 线程终止方式
 * 完成日期: 2018年2月14日 16:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int d1;
	int d2;
}Arg;

void* th_fn(void *arg){
	Arg *r = (Arg*)arg;
	//return (void*)(r->d1+r->d2);
	return (void*)r;
}

int main(void)
{
	pthread_t th;
	Arg r = {20,50};
	if(pthread_create(&th, NULL, th_fn, (void*)&r) != 0)
		handle_error("pthread_create error");
/*
	int *result;
	pthread_join(th, (void**)&result);
	// *result = (r->d1+r->d2)
	printf("result is %d\n", (int)result);
*/
/*	int result;
	pthread_join(th, (void*)&result);
	// result = (r->d1+r->d2);
	printf("result is %d\n", (int)result);
*/
	int *result;
	pthread_join(th, (void**)&result);
	printf("result is: %d\n", ((arg*)result)->d1 + ((arg*)result)->d2);

/*	int result;
	pthread_join(th, (void*)&result);
	printf("result is: %d\n", ((Arg*)result)->d1 + ((Arg*)result)->d2);
*/
	return 0;
}
