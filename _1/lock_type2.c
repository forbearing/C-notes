#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s [error|normal|recursive]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pthread_mutex_t mutex;
	pthread_mutexattr_t mutexattr;

	pthread_mutexattr_init(&mutexattr);
	if(!strcmp(argv[1], "normal")){
		pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_NORMAL);
	}else if(!strcmp(argv[1], "error")){
		pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_ERRORCHECK);
	}else if(!strcmp(argv[1], "recursive")){
		pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
	}else{
		fprintf(stderr, "Usage: %s [error|normal|recursive]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	pthread_mutex_init(&mutex, &mutexattr);
	if(pthread_mutex_lock(&mutex) != 0)
		printf("fisrt lock failure");
	else
		printf("first lock success");
	if(pthread_mutex_lock(&mutex) != 0)
		printf("second lock failure");
	else
		printf("second lock success");

	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex);

	pthread_mutexattr_destroy(&mutexattr);
	pthread_mutex_destroy(&mutex);
	

	return 0;
}
