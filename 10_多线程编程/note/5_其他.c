1:死锁
	1:死锁: 两个线程试图同时占用两个资源,并按不同的次序锁定相应的共享资源
	2:解决方式
		1:按相同的次序锁定相应的共享资源
		2:使用函数 pthread_mutex_trylock(), 它是函数 pthread_mutex_lock()
		  的非阻塞版本


2;线程和信号
	1:进程中每个线程都有自己的信号屏蔽字和信号未决字
	2:信号的处理方式是进程中所有线程共享的
	3:进程中的信号是递送到单个线程的
	4:定时器是进程资源,进程中所有的线程共享相同的定时器
		子线程调用 alarm 函数产生的 alarm 喜好发送给主控线程
	5:线程信号屏蔽函数
		#include <signal.h>
		int pthread_sigmask(int how,
				const sigset_t *restrict set, sigset_t *restrict oset);
		功能: 线程的信号屏蔽
		返回: 成功返回0, 出错返回错误编码


示例
	dead_lock.c
	pthread_alarm.c
	pthread_alarm2.c			// 设置线程的信号屏蔽函数
