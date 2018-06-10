1:线程同步--条件变量
	1:互斥锁的缺点是它只有两种状态: 锁定和非锁定
	2:条件变量通过允许线程阻塞和等待另一个线程发送信号的方法弥补了互斥锁的不足
	3:条件变量内部是一个等待队列,放置等待的线程,线程在条件变量上等待和通知,互斥
	  锁用来保护等待队列(对等待队列上锁),条件变量通常和互斥锁一起使用
	4:条件变量允许线程等待特定条件发生,当条件不满足时,线程通常先进入阻塞状态,
	  等待条件发生,等待条件发生变化. 一旦其他的某个线程改变了田间,可唤醒一个或
	  多个阻塞的线程
	5:具体的判断条件还需用户给出
	6:条件变量类型: pthread_cond_t


2:条件变量创建和销毁
	#include <pthread.h>
	int pthread_cond_init(pthread_cond *restrict cond, 
						pthread_condattr_t *restrict cond);
	int pthread_cond_destroy(pthread_cond_t *cond);
	返回: 成功返回0, 出错返回错误编码
	参数:
		cond: 条件变量
		attr: 条件变量属性
3:条件变量等待操作
	#include <pthread.h>
	int pthread_cond_wait(pthread_cond_t *restrict cond,
						pthread_mutex_t *restrict mutex);
	int pthread_cond_timewait(pthread_cond_t *restrict cond,
		pthread_mutex_t *restrict mutex, const struct timespec *restrict time);
	返回: 成功返回0, 出错返回错误编码号
	struct timespec{
		time_t tv_sec;			// seconds
		long tv_nsec;			// nanoseconds
	}
	>参数:
		cond: 条件变量
		mutex: 互斥锁
	>互斥锁 mutex 是对条件变量 cond 的保护
	>线程由于调用 wait 函数阻塞,否则释放互斥锁
4:条件变量通知操作
	#include <pthread.h>
	int pthread_cond_signal(pthread_cond_t *cond);
	int pthread_cond_broadcast(pthread_cond_t *cond);
	返回: 成功返回0, 出错返回错误编码
	>参数:
		cond: 条件变量
	>当条件满足, 线程需要通知等待的线程
	>pthread_cond_signal 函数通知单个线程
	>pthread_cond_broadcast 函数通知所有线程


5:线程同步和互斥 -- 线程信号量
	1:线程信号量从本质上是一个非负整数计数器,是共享资源的数目,通常被用来控制
	  对共享资源的访问
	2:信号量可以实现线程的同步和互斥
	3:通过 sem_post() 和 sem_wait() 函数对信号量进行加减操作从而解决线程的
	  同步和互斥.
	4:信号量数据类型: sem_t
6:信号量创建和销毁
	#include <semaphore.h>
	int sem_init(sem_t *sem, int pshared, unsigned value);
	int sem_destroy(sem_t *sem);
	1:返回: 成功返回0, 出错返回错误编码
	2:参数:
		sem: 信号量指针
		pshared: 是否在进程间共享的标志,0为不共享,1为共享
	3:value: 信号量的初始值
5:信号量的加和减操作
	#include <semaphore.h>
	int sem_post(sem_t *sem);
	功能: 增加信号量的值
	int sem_wait(sem_t *sem);
	功能: 减少信号量的值
	int sem_trywait(sem_t *sem);
	功能: sem_wait() 的非阻塞版本
	返回: 成功返回0, 出错返回错误编码
	1:调用 sem_post() 一次信号量做加1操作
	2:调用 sem_wait() 一次信号量做减1操作
	3:当线程调用 sem_wait()后, 若信号量的值小于0则线程阻塞, 只有其他线程在调用
	  sem_post() 对信号量做加操作后其其值大于或等于0时,阻塞的线程才能继续运行


总结
	pthread_cond_wait(cond, mutex)函数内部流程{
		1:unlock(&mutex);
		2:lock(&mutex);
		3:将线程自己插入到条件变量的等待队列中;
		4:unlock(&mutex);
		5:当前等待的线程阻塞(等待其他线程通知唤醒);
		6:在唤醒后, lock(&mutex);
		7:从等待队列中删除线程自己
	}


示例:
	pthread_cal.c
	pthread_cal2.c
	reader_writer.c
	sem_test.c
	account2.h		account2.c			// 信号量的线程互斥示例
	pthread_sem_cal.c					// 信号量的线程同步示例
