#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <pthread.h>

typedef struct{
	int code;
	double balance;
	/* 定义一把互斥锁,用来对多线程操作的银行账户(共享资源)进行加锁(保护)的 */
	pthread_mutex_t mutex;
}Account;

/* 创建账户 */
extern Account* create_account(int code, double balance);
/* 销毁账户 */
extern void destroy_account(Account *a);
/* 取款 */
extern double withdraw(Account *a, double amt);
/* 存款 */
extern double deposit(Account *a, double amt);
/* 查看账户余额 */
extern double get_balance(Account *a);

#endif
