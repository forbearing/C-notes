/*
 * 文件名: rwlock_feature.c
 * 描述: 读写锁的特性
 * 完成日期: 2018年2月18号 9:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

pthread_rwlock_t rwlock;

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s [r|w] [r|w]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pthread_rwlock_init(&rwlock, NULL);
	if(!strcmp(argv[1], "r")){
		if(pthread_rwlock_rdlock(&rwlock) != 0)
			printf("first read lock failure\n");
		else
			printf("first read lock success\n");
	}else if(!strcmp(argv[1], "w")){
		if(pthread_rwlock_wrlock(&rwlock) != 0)
			printf("first write failure\n");
		else
			printf("first write success\n");
	}
	if(!strcmp(argv[2], "r")){
		if(pthread_rwlock_rdlock(&rwlock))
			printf("second read lock failure\n");
		else
			printf("second read lock success\n");
	}else if(!strcmp(argv[2], "w")){
		if(pthread_rwlock_wrlock(&rwlock))
			printf("second write lock failure\n");
		else
			printf("second write lock success\n");
	}

	pthread_rwlock_destroy(&rwlock);


	return 0;
}
