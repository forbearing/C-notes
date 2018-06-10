/*
 * 文件名: reader_writer.c
 * 描述: 读者写者问题, 信号量集进行PV 操作实现进程间同步
 * 完成日期: 2018年2月26日 21:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <assert.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	int val;
	int semid;
}Storage;

void init(Storage *s){
	assert(s != NULL);
	/* 创建信号量集(包含2个信号量) */
	if((s->semid = semget(IPC_PRIVATE, 2, IPC_CREAT|IPC_EXCL|0777)) < 0)
		handle_error("semget error");
	/* 对信号量集中的所有信号量初始化 */
	union semun{
		int val;
		struct semid_ds *ds;
		unsigned short *array;
	};
	union semun un;
	unsigned short array[2] = {0, 0};
	un.array = array;
	if(semctl(s->semid, 0, SETALL, un) < 0)
		handle_error("semctl 1 error");
}

void destroy(Storage *s){
	assert(s != NULL);
	if(semctl(s->semid, 0, IPC_RMID, NULL) < 0)
		handle_error("semctl 2 error");
}

void writer(Storage *s, int val){
	assert(s != NULL);
	/* 写入数据到 Storage */
	s->val = val;
	printf("%d write %d\n", getpid(), val);
	struct sembuf ops_v[1] = {{0, 1, SEM_UNDO}};
	struct sembuf ops_p[1] = {{1, -1, SEM_UNDO}};
	/* V(s1) */
	if(semop(s->semid, ops_v, sizeof(ops_v)/sizeof(struct sembuf)) < 0)
		handle_error(" semop error");
	/* P(s2) */
	if(semop(s->semid, ops_p, 1) < 0)
		handle_error("semop error");
}

void reader(Storage *s, int val){
	assert(s != NULL);
	struct sembuf ops_p[1] = {{0, -1, SEM_UNDO}};
	struct sembuf ops_v[1] = {{1, 1, SEM_UNDO}};
	/* P(s1) */
	if(semop(s->semid, ops_p, 1) < 0)
		handle_error("semop error");
	/* 读取数据 */
	printf("%d read %d\n", getpid(), s->val);
	/* V(s2) */
	if(semop(s->semid, ops_v, 1) < 0)
		handle_error("semop error");	
}


int main(void)
{
	/* 将共享资源Storage 创建在共享内存中 */
	int shmid = shmget(IPC_PRIVATE, sizeof(Storage), IPC_CREAT|IPC_EXCL|0777);
	if(shmid < 0)
		handle_error("shmget error");

	/* 父进程进行共享内存映射 */
	Storage *s = (Storage*)shmat(shmid, 0, 0);
	if(s == (Storage*)-1)
		handle_error("shmat error");

	/* 创建信号量并初始化 */
	init(s);


	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){

		int i = 1;
		for(; i<=10; i++)
			writer(s, i);
		wait(0);
		destroy(s);
		shmdt(s);
		shmctl(shmid, IPC_RMID, NULL);

	}else{

		int i = 1;
		for(; i<= 10; i++)
			reader(s, i);
		destroy(s);
		shmdt(s);

	}
	
	return 0;
}
