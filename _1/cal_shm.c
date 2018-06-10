/*
 * 文件名: cal_shm.c
 * 描述: 共享内存的使用
 * 完成日期: 2018年2月26日
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include "tell.h"

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	/* 创建共享内存 */
	int shmid;
	if((shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT|IPC_EXCL|0777)) < 0)
		handle_error("shmget error");


	pid_t pid;
	if((pid = fork()) < 0){
		handle_error("fork error");
	}else if(pid > 0){

		/* 进行共享内存的映射 */
		int *pi = (int*)shmat(shmid, 0, 0);
		if(pi == (int*)-1)
			handle_error("shmat error");
		/* 往共享内存中写入数据 */
		*pi = 100; *(pi+1) = 200;
		/* 操作完毕解除映射 */
		shmdt(pi);
		notify_pipe();					// 通知子线程
		destroy_pipe();
		wait(0);

	}else{

		/* 进行共享内存的映射 */
		wait_pipe();					// 阻塞,等待父进程往共享内存写入数据
		int *pi = shmat(shmid, 0, 0);
		if(pi == (int*)-1)
			handle_error("shmat error");
		/* 从共享内存读取数据并输出 */
		printf("start: %d, end: %d\n", *pi, *(pi+1));
		/* 解除映射 */
		shmdt(pi);
		destroy_pipe();
		/* 删除共享内存 */
		shmctl(shmid, IPC_RMID, NULL);

	}

	return 0;
}
