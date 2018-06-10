#include "account.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>


/* 创建账户 */
Account* create_account(int code, double balance)
{
	Account *a = (Account*)malloc(sizeof(Account));
	assert(a != NULL);
	a->code = code;
	a->balance = balance;
}

/* 销毁账户 */
void destroy_account(Account *a)
{
	assert(a != NULL);
	free(a);
	a = NULL;
}

/* 取款 */
double withdraw(Account *a, double amt)
{
	assert(a != NULL);
	if(amt < 0 || amt > a->balance)
		return 0.0;
	double balance = a->balance;
	balance -= amt;
	a->balance = balance;
	return amt;
}

/* 存款 */
double deposit(Account *a, double amt)
{
	assert(a != NULL);
	if(amt < 0)
		return 0.0;
	double balance = a->balance;
	balance += amt;
	a->balance = balance;
	return amt;
}

/* 查看账户余额 */
double get_balance(Account *a)
{
	assert(a != NULL);
	double balance = a->balance;
	return balance;
}
