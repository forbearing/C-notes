/*
 * 文件名: account_test.c
 * 描述: 共享内存操作银行账户
 * 完成日期: 2018年2月26日
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include "account.h"
#include "pv.h"

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	/* 在共享内存中创建银行账户 */
	int shmid;
	if((shmid = shmget(IPC_PRIVATE, sizeof(Account),
					IPC_CREAT | IPC_EXCL | 0777)) < 0)
		handle_error("shmget error");

	/* 父进程进行共享内存映射并初始化银行账户 */
	Account *a = (Account*)shmat(shmid, 0, 0);
	if(a == (Account*)-1)
		handle_error("shmat error");
	a->code = 100001;
	a->balance = 10000;
	printf("balance: %lf\n", a->balance);


	pid_t pid;
	if((pid = fork()) < 0){
		handle_error("fork error");
	}else if(pid > 0){

		/* 父进程进行取款操作 */
		double amt = withdraw(a, 10000);
		printf("pid %d withdraw %lf from code %d\n", getpid(), amt, a->code);
		/* 查看账户余额 */
		printf("balance: %f\n", get_balance(a));
		/* 解除映射, 对共享内存的操作要在解除映射之前 */
		shmdt(a);
		wait(0);
	
	}else{				// 子进程会继承父进程映射的地址,但不继承创建的共享内存

		/* 子进程也进行取款操作 */
		double amt = withdraw(a, 10000);
		printf("pid %d withdraw %lf from code %d\n", getpid(), amt, a->code);
		/* 查看账户余额 */
		printf("balance: %f\n", get_balance(a));
		/* 解除映射 */
		shmdt(a);
	
	}

	return 0;
}
