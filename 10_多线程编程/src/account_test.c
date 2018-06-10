/*
 * 文件名: account_test.c
 * 描述: 银行账户测试程序
 * 完成日期: 2018年2月17日 7:50
 */

#include "account.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	char name[20];
	Account *account;
	double amt;
}OperArg;

/* 定义取款操作的线程运行函数 */
void* withdraw_fn(void *arg){
	OperArg *oa = (OperArg*)arg;
	double amt = withdraw(oa->account, oa->amt);
	printf("%8s(0x%lx) withdraw %f from account %d\n",
			oa->name, pthread_self(), amt, oa->account->code);
	return (void*)0;
}

/* 定义存款操作的线程运行函数 */
void* deposit_fn(void *arg){
	OperArg *oa = (OperArg*)arg;
	double amt = deposit(oa->account, oa->amt);
	printf("%8s(0x%lx) deposit %f to account %d\n",
			oa->name, pthread_self(), amt, oa->account->code);
	return (void*)0;
}

/* 定义检查银行账户的线程运行函数 */
void* check_fn(void *arg){

}

int main(void)
{
	int err;
	pthread_t boy, girl;
	Account *a = create_account(100001, 10000);

	OperArg o1, o2;
	strcpy(o1.name, "boy");
	o1.account = a;
	o1.amt = 10000;

	strcpy(o2.name, "girl");
	o2.account = a;
	o2.amt = 10000;

	/* 启动两个线程(boy 和 gril 线程), 同时操作同一个银行账户 */
	if((err = pthread_create(&boy, NULL, withdraw_fn, (void*)&o1)) != 0)
		handle_error("pthread_create boy error");
	if((err = pthread_create(&girl, NULL, withdraw_fn, (void*)&o2)) != 0)
		handle_error("pthread_create girl error");

	pthread_join(boy, NULL);
	pthread_join(girl, NULL);
	
	printf("account balance: %lf\n", get_balance(a));

	destroy_account(a);

	return 0;
}
