1:存储映射是一个磁盘文件与存储空间的一个缓存相映射, 对缓存数据的读写就相应的
  完成了对文件的读写


2:mmap 和 munmap 函数
	#include <sys/types.h>
	#include <sys/mman.h>
	void *mmap(void *addr, size_t length, int prot, int flags, \
														int fd, off_t offset
	1:返回: 若成功则返回映射区的起始地址,若出错返回-1
	2:功能: IO使一个磁盘文件与存储空间中的一个缓存相映射
	
	int munmap(void *addr, size_t length);
	1:返回: 成功返回0, 失败返回-1(MAP_FAILED)
	2:功能: 解除映射

	1:mmap 函数从缓存中获取数据,就相当于读文件中的相应字节. 与其类似,将数据存入
	  缓存,则相应字节就自动写入文件. 这样,就可以在不使用 read he write 的情况下
	  执行IO
	2:子进程继承父进程的存储映射区
	3:参数
		1:addr: 存储映射区的起始地址,通常设为0,让系统分配
		2:length: 需要映射的字节数
		3:offset: 映射字节在文件中的偏移量
		4:prot
			PROT_READ		映射区可读
			PROT_WRITE		映射区可写
			PROT_EXEC		映射区执行
			PROT_NONE		映射区不可访问
		5:flags
			MAP_FIXED		返回地址必须等于addr,不鼓励使用
			MAP_SHARED		存储操作立即修改映射文件内容
			MAP_PRIVATE		存储操作导致创建映射文件的副本,并对副本读写


示例:
	file_map.c
	cp_map.c									// 利用存储映射实现文件的拷贝
	mstdio.h	mstdio.c	mstdio_test.c		// 构建标志IO函数库


课后练习
	1:读写方式创建一个空文件 b.txt 若该文件已经存在,则提示用户该文件已经存在,
	  拷贝现有文件 a.txt 内容到 b.txt, 移动文件指针, 读取第6个字符并显示
	2:写一程序,用户每输入一行字符串,将其写入文件中,直到用户输入的字符串为 
	  "exit" 为止
	3:写一程序,将源文件中的小写字母换成大写字母,同时将源文件中大写字符换成
	  小写字母
	4:构建标志的IO函数库
