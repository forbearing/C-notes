1:管道通信
	1:管道是针对于本地计算机的两个进程之间的通信而设计的通信方法,管道建立后,实际
	  获得两个文件描述符: 一个用于读取而另外一个用于写入
	2:最常见的 IPC 机制, 通过 pipe 系统调用
	3:管道是单工的,数据只能向一个方向流动, 需要双向通信时,需要建立起两个管道
	4:数据的读出和写入: 一个进程向管道中写的内容被管道另一端的进程读出. 写入的
	  内容每次都添加在管道缓冲区的末尾,并且每次都是从缓冲区的头部读出数据


2:管道的分类
	1:匿名管道
		1:在关系进程中进行(父进程和子进程,兄弟进程之间)
		2:由 pipe 系统调用,管道由父进程建立
		3:管道位于内核空间, 其实是一块缓存
	2:命名管道(FIFO)
		1:两个没有任何关系的进程之间通信可通过命名管道进行数据传输,本质是内核的
		  一块缓存,另在文件系统中以一个特殊的设备文件(管道文件)存在.
		2:通过系统调用 mkfifo 创建


3:管道创建
	#include <unistd.h>
	int pipe(int fd[2]);
	1:返回: 成功返回0, 出错返回-1
	2:两个文件描述符数组
		fd[0]		为 pipe 的读端
		fd[1]		为 pipe 的写端
		fd[0]用于读取管道, fd[1]用于写入管道
	3:管道主要用于不同进程间通信,实际上,通常先创建一个管道,再通过 fork 函数创建
	  一个子进程


4:协同进程
	1:两个进程通过两个管道进行双向通信


5:管道的读写特性
	1:通过打开两个管道来创建一个双向管道
	2:管道是阻塞性的, 当进程从管道中读取数据,若没有数据进程会阻塞
	3:当一个进程往管道中不断地写入数据但是没有进程去读取数据,此时只要管道没有满
	  是可以的,但若管道放满数据的则会报错
	4:不完整管道
		1:当读一个写端已经关闭的管道时,在所有数据被读取后, read 返回0, 
		  以表示到达了文件尾部
		2:如果写一个读端已经光比的管道,则产生 SIGPIPE, 如果忽略该信号胡捕捉该
		  信号并从处理程序返回,则write 返回-1, 同时 errno 设置为 EPIPE


6:标准库中的管道操作
	#include <stdio.h>
	FILE *popen(const char *cmdstring, const char *type);
	返回值: 成功返回文件指针, 出错返回NULL
	int pclose(FILE *fp);
	返回值: cmdstring 的终止状态, 出错返回-1
	1:使用 popen() 创建的管道必须使用 pclose()关闭,其实, popen/pclose 和标志文件
	  输入/输出流中的 fopen()/fclose()十分相似
	2:封装管道的常见操作
	3:原理
		1:type == "r"
			子进程负责将命令执行结果(exec(cmd))写入管道, 父进程从管道读取命令执
			行的结果并将其放置到 FILE* 类型的文件指针所指向的结构体缓存中
		2:type == "w"
			父进程将结构体缓存中的数据写入管道, 子进程从管道中读取数据
			作为命令(exec(cmd))的输入


7:命名管道(FIFO)创建
	#include <sys/types.h>
	#include <sys/stat.h>
	int mkfifo(const char *pathname, mode_t mode);
	返回: 成功返回0, 出错返回-1
	1:只要对 FIFO 由适当访问权限, FIFO 可用在任何两个没有任何关系的进程之间通信
	2:本质是内核中的一块缓存,另在文件系统中以一个特殊文件(管道文件)存在
	3:在文件系统中只有一个索引块存放文件路径,没有数据块,所以数据存放在内核中
	4:命名管道必须读和写同时打开,否则单独读或者单独写会引发阻塞
	5:命名 mkfifo 创建命名管道(命令内部调用 mkfifo 函数)
	6:对 FIFO 的操作与操作普通文件一样
	7:一旦已经用 mkfifo 创建了一个FIFO, 就可以 open 打开它,一般的文件I/O 函数(
	  close, read, write, unlink 等)都可用于 FIFO
	8:FIFO 相关出错信息
		EACCES(无存取权限)
		EEXIST(指定文件不存在)
		ENAMETOOLONG(路径名太长)
		ENOENT(包含的目录不存在)
		ENOSPC(文件系统剩余空间不足)
		ENOTDIR(文件路径无效)
		EROFS(指定的文件存在于只读文件系统中)

	
8:匿名和命名管道的相同点
	1:默认都是阻塞性读写
	2:都适用于 socket 的网路通信
	3:阻塞不完整管道(有一端关闭)
		1:单纯读时,在所有数据被读取后,read 返回0,以表示到达了文件尾部.
		2:单纯写时,则产生信号 SIGPIPE,如果忽略该信号或捕捉该信号并从处理程序返回
		  则write 返回-1, 同时errno 设置为 EPIPE
	4:阻塞完整管道(两端都开启)
		1:单纯读时,要么阻塞,要么读到数据
		2:单纯写时,写道管道满时会出错
	5:非阻塞不完整管道(有一端关闭)
		1:单纯读时直接报错
		2:单纯写时,则产生信号 SIGPIPE,如果忽略该信号或捕捉该信号并从处理程序返回
		  则write 返回-1, 同时errno 设置为 EPIPE
	6:非阻塞完整管道(两端都开启)
		1:单纯读时直接报错
		2:单纯写时,写道管道满时会出错
9:匿名和命名管道的不同点
	1:打开方式不一致
	2:pipe 通过 fcntl 系统调用来设置 O_NONBLOCK 来设置非阻塞性读写
	3:FIFO 通过 fcntl 系统调用或者open 函数来设置 非阻塞性读写
		  


示例:
	cal_pipe.c
	cmd_pipe.c					// cat /etc/passwd | grep root
	add.c						// 协同进程
	broken_pipe_r.c				// 写端关闭
	broken_pipe_w.c				// 读端关闭
	popen.c						// 标准库函数 popen 的使用
	fifo_read.c					// 命名管道的创建和读取
	fifo_write.c				// 命名管道的创建和写入
	mkfifo.c					// 系统调用 mkfifo 的使用
