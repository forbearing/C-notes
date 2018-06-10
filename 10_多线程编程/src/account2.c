#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "account2.h"
#include <assert.h>

/* 创建账户 */
Account* create_account(int code, double balance){
	Account *a = (Account*)malloc(sizeof(Account));
	assert(a != NULL);
	a->code = code;
	a->balance = balance;
	sem_init(&a->sem, 0, 1);				// 初始化线程信号量,初始值为1
	return a;
}

/* 销毁账户 */
void destroy_account(Account *a){
	assert(a != NULL);
	sem_destroy(&a->sem);
	free(a);
}

/* 取款 */
double withdraw(Account *a, double amt){
	assert(a != NULL);
	sem_wait(&a->sem);			// P(1)
	if(amt < 0 || amt > a->balance){
		sem_post(&a->sem);		// V(1)
		return 0.0;
	}
	double balance = a->balance;
	balance -= amt;
	a->balance = balance;
	sem_post(&a->sem);			// V(1)
	return amt;
}

/* 存款 */
double deposit(Account *a, double amt){
	assert(a != NULL);
	sem_wait(&a->sem);			// P(1)
	if(amt < 0){
		sem_post(&a->sem);		// V(1)
		return 0.0;
	}
	double balance = a->balance;
	balance += amt;
	a->balance = balance;
	sem_post(&a->sem);			// V(1)
	return amt;
}

/* 查看余额 */
double get_balance(Account *a){
	assert(a != NULL);
	sem_wait(&a->sem);
	double balance = a->balance;
	sem_post(&a->sem); 
	return balance;
}
