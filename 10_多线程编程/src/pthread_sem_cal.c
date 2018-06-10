#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int res;
	sem_t sem;
}Result;

void* set_fn(void *arg){
	int i = 1, sum = 0;
	for(; i<=100; i++)
		sum += i;
	Result *r = (Result*)arg;
	r->res = sum;
	sem_post(&r->sem);
	return (void*)0;
}

void* get_fn(void* arg){
	Result *r = (Result*)arg;
	sem_wait(&r->sem);
	int res = r->res;
	printf("0x%lx get sum is %d\n", pthread_self(), res);
	return (void*)0;
}

int main(void)
{
	pthread_t set, get;
	Result r;
	sem_init(&r.sem, 0, 0);
	
	if(pthread_create(&set, NULL, set_fn, (void*)&r) != 0)
		handle_error("pthread_create error");
	if(pthread_create(&get, NULL, get_fn, (void*)&r) != 0)
		handle_error("pthread_create error");

	pthread_join(set, NULL);
	pthread_join(get, NULL);

	sem_destroy(&r.sem);

	return 0;
}
