/*
 * 文件名: pv_my.c
 * 描述: 信号量集进行PV 操作
 * 完成日期: 2018年2月26日 10:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/sem.h>
#include "pv.h"

union semnu{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

int I(int semnums, int value){
	int semid;
	if((semid = semget(IPC_PRIVATE, semnums, IPC_CREAT|IPC_EXCL|0777)) < 0){
		perror("semget error");
		return -1;
	}
	union semnu un;
	unsigned short *array = (unsigned short*)calloc(semnums, sizeof(short));
	int i;
	for(i=0; i<semnums; i++)
		array[i] = value;
	un.array = array;
	if(semctl(semid, 0, SETALL, un) < 0){
		perror("semctl error");
		return -1;
	}
	free(array);
	return semid;
}

int P(int semid, int semnum, int value){
	assert(value >= 0);
	struct sembuf ops[] = {{semnum, -value, SEM_UNDO}};
	if(semop(semid, ops, sizeof(ops)/sizeof(struct sembuf)) < 0){
		perror("semop error");
		return -1;
	}
	return 0;
}

int V(int semid, int semnum, int value){
	assert(value >= 0);
	struct sembuf ops[] = {{semnum, value, SEM_UNDO}};
	if(semop(semid, ops, sizeof(ops)/sizeof(struct sembuf)) < 0){
		perror("semop error");
		return -1;
	}
	return 0;
}
int D(int semid){
	if(semctl(semid, 0, IPC_CREAT, NULL) < 0){
		perror("semctl error");
		return -1;
	}
	return 0;
}
