1:oepn 函数
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	int open(const char *pathname, int flags);
	int open(const char *pathname, int flags, mode_t mode);
	1:返回: 成功返回文件描述符, 出错返回-1
	2:功能: 打开或创建一个文件
	3:参数
		1:pathname: 要打开或者创建的文件路径
		2:flags: 用来说明此函数的多个选项
			O_RDONLY	只读
			O_WRONLY	只写
			O_RDWR		读写
		3:mode: 新建文件的访问权限,对于 open 函数而言,仅当创建新文件时才使用
				第三个参数
	4:open 函数的 falgs 参数
		用下列一个或多个常数进行或运算构成 flags 参数(这些常数定义在<fcntl.h>中)
		1:O_RDONLY		以只读方式打开文件
		2:O_WRONLY		以只写方式打开文件
		3:O_RDWR		以读写方式打开文件
		4:O_APPEND		以追加模式打开文件,每次写时都加到文件的尾端,
						但在网络文件系统进行操作时却没法保证
		5:O_CREAT		如果指定的文件不存在,则按照 mode 参数指定的权限创建文件
		6:O_EXCL		如果同时指定了 O_CREAT, 而文件已经存在,则出错,
						这可测试一个文件是否存在,但在网络文件系统进行操作没保证
		7:O_DIRECTORY	如果参胡 pathname 不是一个目录,则 open 出错
		8:O_TRUNC		如果此文件存在,而且为只读或只写成功打开,
						则将其长度截短为0
		9:O_NONBLOCK	如果 pathname 指的是一个 FIFO, 一个块特殊文件, 一个字符
						特殊文件,则此选项为此文件的本次打开操作和后续的IO操作
						设置非阻塞方式


2:creat 函数
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	int creat(const char *pathname, mode_t mode);
	1:返回: 成功为只写打开的文件描述符,出错返回-1
	2:功能: 创建一个新文件
	3:此函数等效于 open(pathname, O_WRONLY|O_CREAT|O_TRUNC, mode);
	4:creat 的一个不足之处是它以只写方式打开所创建的文件


3:close 函数
	#include <unistd.h>
	int close(int fd);
	1:返回:成功返回0, 失败返回-1
	2:功能: 关闭一个打开的文件
	3:参数
		fd: 已打开文件的文件描述符
	4:当一个进程终止时,它所有的打开文件都由内核自动关闭


4:read 函数
	#include <unistd.h>
	ssize_t read(int fd, void *buf, size_t count);
	1:返回: 读到的字节数,若已到文件尾为0,若出错为-1
	2:参数:
		fd: 读取文件的文件描述符
		buf: 存放读取数据的缓存
		count: 要求读取以此数据的字节数
	3:有多种情况可使实际读到的字节数少于要求读取的字节数
		1:读普通文件时,在读到要求字节数之前已到达了文件尾端
		2:当从终端设备读时,通常一次最多读一行
		3:当从网络读时,网络中的缓冲机构可能造成返回值小于所要求的字节数
		4:某些面向记录的设备,例如磁带,以此最多返回一个记录
		5:进程由于信号造成中断
	4:读操作从文件的位移量处开始,在成功返回之前,该位移量增加实际读得的字节数


5:write 函数
	#include <unistd.h>
	ssize_t write(int fd, const void *buf, size_t count);
	1:返回: 成功返回以写的字节数, 出错为-1
	2:功能: 向打开的文件中写数据
	3:参数:
		fd: 写入文件的文件描述符
		buf: 存放代谢数据的缓存
		count: 要求写入一次数据的字节数
	4:其返回值通常与参数 count 的值不同,否则表示出错
	5:write 出错的的一个常见原因:磁盘已写满,或者超过了一个给定进程的文件长度限制
	6:对于普通文件,写操作从文件的当前位移量开始.如果在打开该文件时,指定了
	  O_APPEND 选项,则在每次写操作之前,将文件位移量设置在文件的当前结尾处.在一次
	  成功写之后,该文件位移量增加实际写的字节数


6:lseek 函数
	#include <sys/types.h>
	#include <unistd.h>
	off_t lseek(int fd, off_t offset, int whence)
	1:返回:成功返回新的文件位移量(绝对偏移量), 出错返回-1
	2:功能: 定位一个已打开的文件
	3:参数
		fd: 已打开文件的文件描述符
		offset: 位移量
		whence: 定位的位置
			SEEK_SET: 将该文件的位移量设置为距文件开始处 offset 个字节
			SEEK_CUR: 将该文件的位移量设置为其当前值加 offset, offset可正可负
			SEEK_END: 将该文件的位移量设置为文件长度加 offset, offset可正可负
	4:lseek 也可用来确定所涉及的文件是否可以设置位移量.如果文件描述符引用的是
	  一个管道或FIFO, 则 lseek 返回-1, 并将 errno 设置为 EPIPE.
	5:每个打开文件都有一个与其相关联的"当前文件偏移量". 它是一个非负整数,用以
	  度量从文件爱呢开始出计算的字节数. 通常,读,写操作都从当前文件偏移量处开始,
	  并使偏移量增加所读或所写的字节数, 按系统默认,当打开一个文件时,除非指定
	  O_APPEND 选项,否则该位移量被设置为0 
	6:lseek 可用来检测文件是否为普通文件和测试长度


其他:
	1:下面两个函数的效果完全相同
		fprintf(stderr, "open error: %s\n", strerror(errno));
		perror("open error");
	2:strerror(errno), 需要包含两个头文件: <string.h>, <errno.h>
	  perror 需要包含 <stdio.h>
	3:O_RDONLY 包含于 <fcntl.h> 头文件中
	4: exit(EXIT_FAILURE) 存在于 <stdlib.h> 头文件中
	5: od -c file		// 查看空洞文件


示例:
	io.h	io.c	cp.c			// 文件复制: open,close,read,write
	length							// 文件长度: lseek
	hole_file.c						// 空洞文件: lseek
