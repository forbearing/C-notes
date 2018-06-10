1:线程概念
	1:进程是资源管理的最小单位,线程是程序执行的最小单位
	2:每个进程有自己的数据段,代码段和堆栈段,线程通常叫做轻型的进程,它包含独立的
	  栈和CPU寄存器状态,线程是进程的一条执行路径,每个线程共享其所附属进程的所有
	  资源,包括打开的文件,内存页面,信号标识及动态分配的内存等
	3:因为线程和进程比起来很小,所以相对来说,线程花费更少的CPU资源
	4:在操作系统设计上,从进程演化出线程,最主要的目的就是更好地支持多处理器,并且
	  减小进程上下文切换的开销
	5:进程和线程关系
		线程和进程的关系是: 线程属于进程的,线程运行在进程空间中,同一进程所产生
		的线程共享同一用户内存空间,当进程退出时该进程所产生的线程都会被强制退出
		并清除,一个进程至少需要一个线程作为它的指令执行体. 进程管理着资源(比如:
		CPU, 内存, 文件等),而将线程分配到某个CPU上执行
	6:在线程运行函数中的局部变量是线程各自拥有一份
	7:线程编程中,尽量使用局部变量


2:线程分类
	1:线程按照其调度者可分为用户级线程和内核级线程两种
		用户级线程: 主要解决的是上下文切换的问题,其调度过程由用户决定
		内核级线程: 由内核调度机制实现
	2:现在大多数操作系统都采用用户级线程和内核级线程并存的方法
	3:用户级线程要绑定内核级线程运行,一个进程中的内核级线程会分配到固定的时间片,
	  用户级线程分配的时间片以内核级线程为准
	4:默认情况下,用户级线程和内核级线程是一对一的,也可以是多对一,这样实时性较差
	5:当CPU 分配给线程的时间片用完后但线程没有执行完毕,此时线程会从运行状态返回
	  到就绪状态, 将CPU 让给其他线程使用


3:Linux 线程的实现
	1:以下线程均为用户级线程, 在Linux 中,一般采用pthread 线程库实现线程的访问和
	  控制, 由POSIX 提出,具有良好的可移植性
	2:Linux 线程编译需要在 gcc 上链接库 pthread


4:线程标志
	1:每个进程内部的不同线程都有自己的唯一标识(ID)
	2:线程标识旨在它所属的进程环境中有效
	3:线程标识是 pthread_t 数据类型
	#include <pthread.h>
	int pthread_equal(pthread_t , pthread_t);
	1:功能: 判断两个线程的ID是否相等
	1:返回: 成功返回非0, 否则返回0
	pthread_t pthread_self(void);
	返回: 调用线程的线程ID 


5:线程创建
	#include <pthread.h>
	int pthread_create(pthread_t *restrict tidp, 
			const pthread_attr_t *restrict attr, void*(*start_rtn)(void*), 
			void *restrict arg);
	1:参数:
		tidp: 线程标识符指针
		attr: 线程属性指针
		start_rtn: 线程运行函数的起始地址
		arg: 传递给线程运行函数的参数
	2:新创建线程从 start_rtn 函数的地址开始执行
	3:不能保证新线程和调用线程的执行顺序 


6:线程终止
	#include <pthread.h>
	int pthread_cancel(pthread_t tid);
	void pthread_exit(void *retval);
	int pthread_join(pthread_t th, void**(thread_return));
	返回值: 成功返回0, 否则返回错误编码
	1:pthread_cancel:
		进程可以被同一进程的其他线程取消, tid 为被终止的线程标识符
	2:pthread_exit
		1:retval: pthread_exit 调用者线程的返回值,可由其他函数和 pthread_join
		  来检测获取
		2:线程退出时使用函数 pthread_exit 是线程的主动行为
		3:由于一个进程中的多个线程共享数据段,因此通常在线程退出后,退出线程所占用
		  的资源并不会随线程的结束而释放,所以需要 pthread_join 函数来等待线程
		  结束,类似于 wait 系统调用
		4:pthread_join
			th: 被等待线程的标识符
			thread_return: 用户定义指针,用来存储被等待线程的返回值
	3:线程终止方式
		1:主动终止
			线程的执行函数调用 return 语句
			调用 pthread_exit()
		2:被动终止
			线程可以被同一进程的其他线程取消,其他线程调用 pthread_cancel(tlp);
			线程运行函数调用 exit 函数会导致进程终止


8:线程清理和控制函数
	#include <pthread.h>
	void pthread_cleanup_push(void(*rtn)(void*), void *arg);
	void pthread_cleanup_pop(int execute);
	1:参数
		rtn: 清理函数指针
		arg: 调用清理函数传递的参数
		execute: 值1时执行线程清理函数, 值0时不执行清理函数
	2:触发线程调用清理函数的动作
		1:调用 pthread_exit
		2:响应取消请求(pthread_cancel)
		3:用非零 execute 参数调用 thread_cleanup_pop 时


9:进程,线程启动和终止方式的比较
10:线程的状态切换


11:线程属性
	#include <pthread.h>
	int pthread_attr_init(pthread_attr_t *attr);
	int pthread_attr_destroy(pthread_attr_t *attr);
	返回: 成功返回0, 否则返回错误编号
	1:线程属性结构体
	typedef struct{
		int		etachstate;				// 线程的分离状态
		int		schedpolicy;			// 线程调度策略
		structsched_param	schedparam;	// 线程的调度参数
		int		inheritsched;			// 线程的继承性
		int		scope;					// 线程的作用域
		size_t	guardsize;				// 线程栈末尾的警戒缓冲区大小
		int		stackaddr_set;			// 线程的栈设置
		void*	stackaddr;				// 线程栈的位置
		size_t	stacksize;				// 线程栈的大小
	}pthread_attr_t;
12:设置和获得分离属性
	#include <pthread.h>
	int pthread_attr_getdetachstate(const pthread_attr_t *restrict attr,
			int *detachstate);
	int pthread_attr_setdetachstate(const pthread_attr_t *attr, int detachstate)
	1:detachstate 取值
		PTHREAD_CREATE_JOINABLE:		默认值,正常启动
		PTHREAD_CREATE_DETACHED:		以分离状态启动线程
	2:以默认方式启动的线程,在线程结束后不会自动释放占有的系统资源,要在主控线程中
	  调用 pthread_join() 后才会释放
	3:以分离状态启动的线程,在线程结束后会自动释放所占有的系统资源
	4:分离属性在网络通讯中使用的较多


示例
	pthread_race.c
	pthread_race2.c
	pthread_join.c
	pthread_clean.c
	pthread_detach.c					// 线程分离属性
	pthread_detach_my.c
