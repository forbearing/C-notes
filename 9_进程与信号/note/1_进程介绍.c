1:进程
	1:程序:
		程序(program)是存放在磁盘文件中的可执行文件
	2:进程
		1:程序的执行实例被称为进程(process)
		2:进程具有独立的权限与职责,如果系统中某个进程崩溃,它不会影响到其余的进程
		3:每个进程运行在各自的虚拟地址空间中,进程之间可以通过由内核控制的机制
		  来相互通讯
	3:进程ID
		每个 Linux 进程都一定有一个唯一的数字标识符,称为进程 ID(process ID),
		进程 ID 总是一非负整数


2:内核中的进程结构
	1:每一个启动的进程都有一个进程表项(进程控制块), 
	  它实际为一个结构体 task_struct
	2:进程表项(进程控制块)结构体声明的头文件: 
		/usr/src/linux-headers-$(uname -r)/include/linux/sched.h
		(搜索 "struct task_struct")


3:C程序启动过程
	1:内核启动特殊例程
	2:启动例程:
		1:在进程的 main 函数执行之前内核会启动
		2:该进程放置在 /lib/libc.so.*** 中
		3:编译器在编译时会将启动例程编译进可执行文件中
	3:启动例程的作用
		1:搜集命令行的参数传递给 main 函数的 argc 车 argv
		2:搜集环境信息构建环境表(指针数组)并传递给 mian 函数
		3:登记进程的终止函数


4:进程的终止方式
	1:正常终止
		1:从 main 函数返回
		2:调用 exit(标准C库函数)
		3:调用 _exit 或 _Exit(系统调用)
		4:最后一个线程调用 pthread_exit
	2:异常终止
		1:调用 abort
		2:接受一个信号并终止
		3:最后一个线程对取消请求做处理响应
	3:进程返回:
		1:通常程序运行成功返回0, 否则返回非0
		2:在 shell 中可以查看进程返回值(echo $?)


5:进程终止方式区别
							return		exit()	_exit()/_Exit()
	是否刷新I/O缓存			是			是		否
	是否自动调用终止函数	是			是		否则返回非


6:进程启动和退出
7:atexit 函数
	#include <stdlib.h>
	int atexit(void (*function)(void));
	1:返回: 成功返回0, 出错返回-1
	2:功能:向内核登记终止函数
	3:备注
		1:每个启动的进程都默认登记了一个标准的终止函数
		2:终止函数在进程终止时释放进程所占用的一些资源
		3:等级的多个终止函数执行顺序是按栈的方式执行的,先登记的后执行 
	4:_exit()函数在 <unistd.h> 头文件声明
	5:_exit() 或_Exit() 的进程返回,并不会调用进程的终止函数


8:环境表
	int main(int argc, char *argv[], char envp[])
	extern char **environ;
	1:每个进程都有一个独立的环境表
	2:初始环境表继承自父进程


9:环境变量操作函数
	#include <stdlib.h>
	char *getenv(const char *name);
	1:返回: 指向与 name 关联的 value 的指针,若未找到则返回 NULL
	2:功能: 获取环境变量
	int putenv(char *str)
	1:返回: 成功返回0, 出错返回-1
	2:功能: 形式为 name=value 的字符串,将其放到环境表中
			如果 name 已经存在,则先删除其原来的定义
	int setenv(const char *name, const char *value, int rewrite);
	1:返回: 成功返回0, 出错返回-1
	2:功能: 将 name 设置为 value, 如果在环境中 name 已经存在. 如果 rewrite 为
			非0, 则首先删除其现存的定义, 如果 rewrite 为0, 则不删除其现定义
			(name 不设置为新的 value,而且也不出错)
	int unsetenv(const char *name)
	1:返回: 成功返回0, 出错返回-1
	2:功能: 删除 name 的定义,即使不存在这种定义也不算出错


示例
	process_term.c
	process_env.c
	process_env2.c
