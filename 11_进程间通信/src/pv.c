/*
 * 文件名: pv.c
 * 描述: 信号量集进行PV 操作
 * 完成日期: 2018年2月26日 10:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sem.h>
#include <assert.h>
#include "pv.h"

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

/* 初始化 semnums 个信号灯/信号量的值(value) */
int I(int semnums, int value){
	/* 1:创建信号量集 (决定信号量集中信号量的个数) */
	int semid;
	if((semid = semget(IPC_PRIVATE, semnums, IPC_CREAT|IPC_EXCL|0777)) < 0){
		perror("semget error");
		return -1;
	}
	/* 2:操作信号量集 (决定信号量集中每个信号量的值) */
	union semun un;
	unsigned short *array = (unsigned short *)calloc(semnums, sizeof(short));
	int i;
	for(i=0; i<semnums; i++){
		array[i] = value;
	}
	un.array = array;
	if(semctl(semid, 0, SETALL, un) < 0){		// 0表示初始化所有的信号灯
		perror("semctl error");
		return -1;
	}
	free(array);
	return semid;
}

/* 对信号量集(semid)中的某个信号灯(semnum)做P(value)操作 */
void P(int semid, int semnum, int value){
	assert(value >= 0);
	/* 定义sembuf 类型的结构体数组,放置若干个结构体变量,对应要操作的信号量
	 * 结构体数组中有多少个成员就操作多少个信号量*/
	struct sembuf ops[] = {{semnum, -value, SEM_UNDO}};
	if(semop(semid, ops, sizeof(ops)/sizeof(struct sembuf)) < 0)
		perror("semop error");
}

/* 对信号量集(semid)中的某个信号灯(semnum)做V(value)操作 */
void V(int semid, int semnum, int value){
	assert(value >= 0);
	struct sembuf ops[] = {{semnum, value, SEM_UNDO}};
	if(semop(semid, ops, sizeof(ops)/sizeof(struct sembuf)) < 0)
		perror("semop error");
}

/* 销毁信号量集 */
void D(int semid){
	if(semctl(semid, 0, IPC_RMID, NULL) < 0)
		perror("semctl error");
}
