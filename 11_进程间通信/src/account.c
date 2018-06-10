/*
 * 文件名: account.c
 * 描述: 共享内存操作银行账户
 * 完成日期: 2018年2月26日 8:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "account.h"

/* 取款 */
double withdraw(Account *a, double amt){
	assert(a != NULL);
	P(a->semid, 0, 1);
	if(amt < 0 ||  amt > a->balance){
		V(a->semid, 0, 1);
		return 0.0;
	}
	double balance = a->balance;
	balance -= amt;
	a->balance = balance;
	V(a->semid, 0, 1);
	return amt;
}

/* 存款 */
double deposit( Account *a, double amt){
	assert(a != NULL);
	P(a->semid, 0, 1);
	if(amt < 0){
		V(a->semid, 0, 1);
		return 0.0;
	}
	double balance = a->balance;
	balance += amt;
	a->balance = balance;
	V(a->semid, 0, 1);
	return amt;
}

/* 查看账户余额 */
double get_balance(Account *a){
	assert(a != NULL);
	P(a->semid, 0, 1);
	double balance = a->balance;
	V(a->semid, 0, 1);
	return balance;
}
