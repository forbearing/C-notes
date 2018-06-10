1:线程的同步和互斥概念
	1:线程同步
		1:是一个宏观概念,在微观上包含线程的相互排斥和线程先后执行的约束问题
		2:解决同步方法: 
			条件变量
			线程信号量
	2:线程互斥
		1:线程执行的相互排斥
		2:解决互斥方法
			互斥锁
			读写锁
			线程信号量


2:线程互斥--互斥锁
	1:互斥锁(mutex)是一种简单的加锁的方法来控制对共享资源的访问,在同一时刻只能有
	  一个线程掌握某个互斥锁,拥有上锁状态的线程能够对共享资源进行访问. 若其他线
	  程希望上锁一个已经被上了互斥锁的资源,则线程挂起,直到上锁的线程释放互斥锁
	2:互斥锁数据类型
		pthread_mutex_t
	3:建议互斥锁用来锁定一个账户(共享资源),和账户绑定在一起, 尽量不设置成全局
	  变量,否则可能出现一把锁区锁几百个账户,导致并发性降低
	4:上锁区域称为临界区
3:互斥锁的创建和销毁
	#include <pthread.h>
	int pthread_mutex_init(pthread_mutex_t* restrict mutex,
			const pthread_mutexattr_t *mutexattr);
	int pthread_mutex_destroy(pthread_mutex_t *mutex);
	1:返回:成功返回0, 否则返回错误编码
	2:参数	
		mutex: 互斥锁
		mutexaddr: 互斥锁创建创建方式
			PTHREAD_MUTEX_INITIALIZED					创建快速互斥锁
			PTHREAD_RECURSIVE_MUTEX_INITIALIZED_NP		创建递归互斥锁
			PTHREAD_ERRORCHECK_MUTEX_INITALIZED_NP		创建检查互斥锁
4:互斥锁上锁和加锁
	#include <pthread.h>
	int pthread_mutex_lock(pthread_mutex_t *mutex);
	功能: 上锁,拿不到锁阻塞
	int pthread_mutex_trylock(pthread_mutex_t *mutex);
	功能: 上锁,拿不到锁返回出错信息
	int pthread_mutex_unlock(pthread_mutex_t *mutex);
	功能: 释放锁
	返回: 成功返回0,出错返回错误码


5:互斥锁属性的创建和销毁
	#include <pthread.h>
	int pthread_mutexattr_init(pthread_mutexattr_t *attr);
	int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
	返回值: 成功返回0, 出错返回错误编码
6:互斥锁进程共享属性操作
	#include <pthread.h>
	int pthread_mutexattr_getpshared(
			const pthread_mutexattr_t *restrict attr, int *restrict pshared);
	int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared);
	1:返回: 成功返回0, 出错返回错误编码
	参数:
		attr: 互斥锁属性
		pshared: 进程共享属性
			PTHREAD_PROCESS_PRIVATE(默认情况)
				锁只能用于一个进程内部的两个线程进行互斥
			PTHREAD_PROCESS_SHARED
				所可以用于两个不同进程中的线程进行互斥
7:互斥锁类型操作
	#include <pthread.h>
	int pthread_mutexattr_gettype(
			const pthread_mutexattr_t *restrict attr, int *restrict type);
	int pthread_mutexattr_settype(pthread_mutexattr_t *attr, int type);
	1:返回: 成功返回0, 出错返回错误编码
	2:参数:
		attr: 互斥锁属性
		type: 互斥锁类型
			1:标准互斥锁: PTHREAD_MUTEX_NORMAL
				第一次上锁成功,第二次上锁会阻塞
			2:递归互斥锁: PTHREAD_MUTEX_RECURSIVE
				第一次上锁成功, 第二次上锁还是成功, 内部计数
			3:检查互斥锁: PTHREAD_MUTEX_ERRORCHECK
				第一次上锁成功,第二次上锁会出错
			4:默认互斥锁: PTHREAD_MUTEX_DEFAULT (同标准互斥锁)
				第一次上锁成功, 第二次上锁会阻塞


8:线程互斥--读写锁
	1:线程使用互斥锁缺乏读并发性
	2:当读操作较多,写操作较少时,可使用读写锁提高线程并发性
	3:读写锁数据类型: pthread_rwlock_t
9:读写锁创建和销毁
	#include <pthread.h>
	int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
			const pthreat_rwlockattr_t *restrict attr);
	int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
	参数: 
		rwlock: 读写锁
		attr: 读写属性
10:读写锁加锁和解锁
	#include <pthread.h>
	int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
	功能: 加读锁
	int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
	功能: 加写锁
	int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
	功能: 释放锁
	返回: 成功返回0, 出错返回错误编码
	参数:
		rwlock: 读写锁


总结
	1:互斥锁系统调用
		pthread_mutexattr_init(&mutexattr)
		pthread_mutexattr_getpshared
		pthread_mutexattr_gettype
		pthread_mutexattr_setpshared
		pthread_mutexattr_settype
		pthread_mutex_init(&mutex, &mutexattr);
		pthread_mutex_lock(&mutex)
		pthread_mutex_trylock(&mutex)
		pthread_mutex_unlock(&mutex)
		pthread_mutexattr_destroy(&mutexattr);
		pthread_mutex_destroy;(&mutex);
	2:互斥锁注意事项
		1:锁属性操作和锁操作之前都要进行初始化(init)
		2:锁属性操作(pthread_mutexattr_settype)之后才是
		  锁操作初始化(pthread_mutex_init)
		3:先销毁锁属性,再销毁锁
	3:读写锁系统调用
		pthread_rwlock_init(&rwlock, NULL);
		pthread_rwlock_rdlock(&rwlock);
		pthread_rwlock_wrlock(&rwlock);
		pthread_rwlock_unlock(&rwlock);
		pthread_rwlock_destroy(&rwlock);


示例
	account.h		account.c		account_test.c
	lock_type.c
	rwlock_feature.c					// 读写锁的特性
