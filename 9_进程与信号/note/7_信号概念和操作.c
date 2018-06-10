1:信号的基本概念
	1:信号(Signal)机制是 Linux 系统中最为古老的进程之间的通信机制, 解决进程正在
	  运行过程中被中断的问题,导致进程的处理流程会发生变化
	2:信号是软件中断
	3:信号是异步事件
		1:不可预见
		2:信号有自己的名称和编号
		3:信号和异常处理机制
	4:信号发生的来源
		1:硬件来源: 比如我们按下了键盘或者其他硬件故障,信号是由硬件驱动程序产生
		2:软件来源: 最常见发送信号的系统函数是 kill(), raise(), alarm() 和 
		  setitimer() 等函数. 软件来源还包括一些非法运算等操作,软件设置条件(如:
		  gdb调试). 信号是由内核产生
	5:1-31为非实时信号, 31-64为实时信号
		非实时信号特点
			发送的信号可能会丢失
			不支持信号排队
			(信号无优先级)
		实时信号特点
			发送的信号都会被接受
			支持信号排队
			(信号无优先级)
	6:相关头文件
		/usr/include/x86_64-linux-gnu/bits/signum.h
	7:信号
		SIGINT		1		终端, Ctrl-C
		SIGQUIT		3		退出
		SIGILL		4		执行非法指令
		SIGTRAP		5		Trace trap(POSIX) 浮点运算错误
		SIGABRT		6		abort 系统调用产生
		SIGFPE		8		Floating-point exception (ANSI)
		SIGKILL		9		kill -9
		SIGUSR1		10		User-defined signal 1
		SIGSEGV		11		Segmentation fault
		SIGUSR2		12		User-defined signal 2
		SIGPIPE		13		Broken pipe (POSIX)
		SIGALRM		14		Alarm clock, alarm 系统调用产生
		SIGTERM		15		Termination
		SIGSTKFLT	16		Stack fault
		SIGCHLD		17		避免僵尸进程
		SIGCONT		18		Continue
		SIGSTOP		19		Stop, unblockable
		SIGTSTP		20		Keyboard stop, Ctrl-Z
		SIGTTIN		21		Background read from tty, 后台进程读
		SIGTTOU		22		Background write to tty, 后台进程写


2:信号的处理和变革
	1:信号的处理
		进程可以通过三种方式来响应和处理一个信号
		1:忽略信号
			SIGKILL 和 SIGSTOP 永远不能忽略
			忽略硬件异常
			进程启动时 SIGUSR1 和 SIGUSR2 两个信号被忽略
		2:执行默认操作
			每个信号都有默认动作,大部分信号默认动作就是终止进程
		3:捕获信号
			告诉内核出现信号时调用自己的处理函数
			SIGKILL 和 SIGSTOP 不能被捕获
	2:信号变革
		1:信号出现在早期的 Unix 中
		2:早期信号模型是不可靠的
		3:BSD 和 System V 分别对早期信号进行扩展,但是相互不兼容
		4:POSIX 同一了上述两种模型,提供了可靠信号模型


3:signal 函数
	#include <signal.h>
	void(*signal(int signo, void(*func)(int)))(int);
	1:返回: 成功返回先前的信号处理函数指针(当前信号处理函数地址), 
			出错则返回 SIG_ERR
	2:功能: 向内核登记信号处理函数
	3:参数
		signo: 要登记的信号
		func: 信号处理函数指针
			SIG_IGN: 忽略信号
			SIG_DFL: 采用系统默认的方式处理信号,执行默认操作


4:SIGCHLD 信号
	1:子进程状态发生变化(子进程结束)产生该信号,父进程需要 wait 调用来
	  等待子进程结束并回收它
	2:避免僵尸进程


5:信号发送
	1:除了内核和超级用户,并不是每个进程都可以向其他的进程发送信号
	2:一般的进程只能向buyout相同 uid 和 gid 的进程发送信号,或向相同
	  进程组中的其他进程发送信号
	3:常见的发送信号的函数有 kill(), raise(), alarm(), setitimer(),
	  abort() 等
6:信号发送函数
	#include <signal.h>
	int kill(pid_t pid, signo);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 向指定的进程发送某一个信号
	int raise(int signo);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 向进程本身发送一个信号,相当于kill(getpid(), signo);
	3:kill 函数将信号发送给进程或进程组
		0为空信号,常用来检测特定的进程是否存在 
	4:kill 函数参数 pid 取值
		pid > 0		将信号发送给进程ID为 pid 的进程
		pid == 0	将信号发送给与发送进程同一进程组的所有进程
		pid < 0		将该信号发送给进程ID等于 pid 的绝对值
		pid == -1	将该信号发送给发送进程有权限向他们发送信号的系统上
					所有进程


7:定时器
	#include <unistd.h>
	unsigned int alarm(unsigned int seconds);
	1:返回: 0或以前设置的定时器时间余留秒数
	2:alarm 函数可以设置定时器,当定时器超时,产生 SIGALRM 信号
	3:信号由内核产生,在指定的 second秒之后,给进程本身发送一个 SIGALRM 信号
	4:参数为0, 取消以前设置的定时器
	5: ualarm 微秒级别


总结
	1:SIGKILL 和 SIGSTOP 信号不能被信号处理函数 signal 处理,否则出错  
	2:SIGTSTP(Ctrl-D), SIGINT(Ctrl-C) 的默认处理方式(SIG_DFL),分别是
	  后台进行,中断程序


示例
	signal_catch.c						// signal 函数的使用
	signal_child.c						// 信号 SIGCHLD 的使用
	raise_kill.c						// raise, kill 函数的使用
	signal_alarm.c						// alarm 函数的使用
