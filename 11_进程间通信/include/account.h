/*
 * 文件名: account.h
 * 描述: 共享内存操作银行账户
 * 完成日期: 2018年2月26日 8:40
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

typedef struct{
	int code;
	double balance;
	int semid;
}Account;

/* 取款 */
extern double withdraw(Account *a, double amt);
/* 存款 */
extern double deposit(Account *a, double amt);
/* 查看账户余额 */
extern double get_balance(Account *a);

#endif
