1:dup 和 dup2 函数
	#include <unistd.h>
	int dup(int oldfd);
	int dup2(int oldfd, int newfd);
	1:返回: 成功返回新文件描述符, 出错返回-1
	2:功能: 文件描述符的复制
	3:参数:
		oldfd: 原先的文件描述符
		newfd: 新的文件描述符
	4:由 dup 返回的新文件描述符一定是当前可用文件描述符中的最小数值
	5:用 dup2 则可以用 newfd 参数指定新描述符的数值.如果 newfd 已经打开,则向将其
	  关闭,如若 oldfd 等于 newfd, 则 dup2 返回 newfd, 而不是关闭它
	6:在进程间通信时可用来改变进程的标准输入和标准输出设备


2:fcntl 函数
	#include <unistd.h>
	#include <fcntl.h>
	int fcntl(int fd, int cmd);
	int fcntl(int fd, int cmd, long arg);
	int fcntl(int fd, int cmd, struct flock *lock);
	1:返回: 若成功则依赖于 cmd, 若出错返回-1
	2:功能: 可以改变已经打开文件的性质
	3:常见的功能:
		1:复制一个现存的描述符,新文件描述符作为函数返回值(cmd=F_DUPFD)
		2:获取/设置文件描述符标志(cmd=F_GETFD 或 F_SETFD)
		3:获取/设置文件状态标志(cmd=F_GETFL 或 F_SETFL)
		4:获取/设置文件锁(cmd=F_SETLK, cmd=F_GETLK, cmd=F_SETLKW)
			第三个参数为 struct flock 结构体
	4:cmd 的常见取值
		1:F_DUPFD: 复制文件描述符,新的文件描述符作为函数返回
		2:F_GETFD/F_SETFD: 获取/设置文件描述符,通过第三个参数设置
		3:F_GETFL/F_SETFL: 
			获取/设置文件状态标志,通过第三个参数设置
			可以更改的借个标志是 O_APPEND, O_NONBLOCK, SYNC O_ASYNC
				(O_RDONLY, O_WRONLY, O_RDWR 不适用)


3:ioctl 函数
	#include <unistd.h>
	#include <sys/ioctl.h>
	int ioctl(int fd, int request, ...);
	1:返回: 若成功则为其他值,出错返回-1
	2:IO操作的杂物箱,不能用本章中其他函数表示的IO操作通常都能用 ioctl 表示, 终端
	  IO是 ioctl的最大使用方面,主要用于设备的IO控制


其他:
	1:cat 的使用
		cat						// 输入输出为标准输入和标准输出
		cat < mypasswd			// 输入重定向,等同于 cat mypasswd
		cat > file				// 输出重定向,输入为标准输入
		cat mypasswd > wokao	// 输出重定向,输入为文件


示例:
	cat.c						// cat 命令的实现
	mcat.c						// dup2 函数实现重定向
	io.h(set_fl, clr_fl)	io.c	fcntl.c
	readkey.c					// ioctl
