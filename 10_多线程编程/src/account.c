#include "account.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <unistd.h>
#include <pthread.h>


/* 创建账户 */
Account* create_account(int code, double balance)
{
	Account *a = (Account*)malloc(sizeof(Account));
	assert(a != NULL);
	a->code = code;
	a->balance = balance;
	pthread_mutex_init(&a->mutex, NULL);
}
/* 销毁账户 */
void destroy_account(Account *a)
{
	assert(a != NULL);
	free(a);
	//a = NULL;
	pthread_mutex_destroy(&a->mutex);
}
/* 取款 */
double withdraw(Account *a, double amt)
{
	assert(a != NULL);
	pthread_mutex_lock(&a->mutex);
	if(amt < 0 || amt > a->balance){
		pthread_mutex_unlock(&a->mutex);
		return 0.0;
	}
	double balance = a->balance;
	sleep(1);
	balance -= amt;
	a->balance = balance;
	pthread_mutex_unlock(&a->mutex);
	return amt;

}
/* 存款 */
double deposit(Account *a, double amt)
{
	assert(a != NULL);
	pthread_mutex_lock(&a->mutex);
	if(amt < 0){
		pthread_mutex_unlock(&a->mutex);
		return 0.0;
	}
	double balance = a->balance;
	sleep(1);
	balance += amt;
	a->balance = balance;
	pthread_mutex_unlock(&a->mutex);
	return amt;
}
/* 查看账户余额 */
double get_balance(Account *a)
{
	assert(a != NULL);
	pthread_mutex_lock(&a->mutex);
	double balance = a->balance;
	pthread_mutex_unlock(&a->mutex);
	return balance;
}
