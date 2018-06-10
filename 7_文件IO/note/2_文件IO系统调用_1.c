1:函数
	open()		打开文件
	create()	创建文件
	cloase()	关闭文件
	read()		读取文件
	write()		写入文件
	lseek()		文件定位
	1:这些不带缓存的函数都是内核提供的系统调用,它们不是 ANSI 的组成部分,但是
	  POSIX 的组成部分
	3:系统调用与C库关系
		1:应用代码 --> C库函数 --> 系统调用
		2:应用代码 --> 系统调用

2:文件操作方式
	1:标准库函数
		遵循 ISO 标准,基于流的IO,对文件指针(FILE结构体指针)进行操作
	2:系统调用
		兼容 POSIX 标准, 基于文件描述符的IO,对文件描述符进行操作


3:文件描述符
	1:对于内核而言,所有打开文件都由文件描述符引用. 文件描述符是一个非负整数.当
	  打开一个现存文件或创建一个新文件时,内核向进行返回一个文件描述符. 当读,写
	  一个文件时,用 open 或 create 返回一个文件描述符标识该文件,将其作为参数传送
	  给 read  或 write
	2:在 POSIX 应用程序中,整数0,1,2被替换成符号常量 STDIN_FILENO, STDOUT_FILENO
	  STDERR_FILENO. 这些常量都定义在头文件 <unistd.h> 中
	3:文件描述符的范围是 0--OPEN_MAX, 早期的 UNIX 版本采用的上限值是19(允许每个
	  进行打开20个文件),现在很多系统则将其增加至63, Linux 为1024


4:文件描述符与文件指针
	1:标准文件指针
		stdin	0
		stdout	1
		stderr	2
	2:fdopen()
		FILE *fdopen(int fd, const char *mode);
		文件描述符->文件指针(fd->FILE*)
		mode: "r","rw" 等
	fileno()
		int fileno(FILE *stream);
		文件指针->文件描述符(FILE*->fd)
