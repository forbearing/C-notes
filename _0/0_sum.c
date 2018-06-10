1:函数主题尽量不要出现复杂代码,复杂逻辑代码尽量用函数封装起来
2:多使用 #define 符号常量
3:注意在某些场合下需要使用 static 来修饰变量和函数
4:函数的形参和返回值根据场合勤使用 const 关键字
	char const *lookup_addr(char const *name);
5:程序设计思路:
	1:从复杂到细节, 
	2:复杂代码用函数封装, 重复代码用函数封装
	3:如果多个不同函数中的代码片段有重复,可再封装一个函数, 然后多个不同函数
	  调用这个函数.
		static int find_index(char const *find_to_name)
		char const *lookup_phone(char const *name){
			int index = find_index(name);
			if(index == -1)
				return NULL;
			else
				return phone[i];
		}
		char const *lookup_address(char const *name){
			int index = find_index(name);
			if(index == -1)
				return NULL;
			else
				return address[i];
		}
6:多使用目标文件(.o文件,只是编译过,没有链接), 方便敲命令
7:#define 定义 放在 头文件(.h文件)中
8:数据结构的定义可以放在头文件中,也可以放在头文件对应的 .c 文件中
9:善用 typedef, typedef unsigned int uint_t;
10:操作指针通常要判断是否为空, 如函数的形参

11:动态数组相关
	element.h
	teacher.h
	teacher.c
	teacher_test.c
	1:数据结构的声明放在 element.h 中
	2:操作函数声明在 teacher.h
	3:操作函数的定义在 teacher.c 中
	4:额外需要的的函数
		1:判断动态数组是否满: is_full()
		2:判断动态数组是否空: is_empty()
		3:扩展动态数组:	resize()
		并且这些函数放在 teacher.c 中, 并且需要 static 修饰
	其他:
		1:善用 typedef
			typedef struct teacher ElementType
			typedef struct teacher* ElementType
			typedef unsigned int uint_t
		2:善用 static
			static uint_t is_full()
			static uint_t is_empty()
			static void resize(uint_t increment);

12:标准IO函数库实现原理
	1:文件 <-> 缓存
		1:读: 缓存空,就使用 read 函数从文件中读取内容到缓存中
		2:写: 缓存满,就使用 write 函数从缓存中写入内容到缓存中
	2:源文件缓存 <-> 目标文件缓存
		1:字符读写函数
			中间有一个字符来做临时存储
			源文件缓存 -> fgetc -> char ch -> fputc -> 目标文件缓存
		2:字符串读写函数
			中间有一个字符数组(缓存)来临时存储
			源文件缓存 -> fgets -> char buff[n] -> fputs -> 目标文件缓存

13:memset 的使用点
	正确
		struct stat buf
		memset(&buf, 0, sizeof(buf));
	错误:
		struct stat *buf
		memset(buf, 0, sizeof(buf));
		// 因为 buf 指针没有指向任何 struct stat 结构体, 为野指针
	正确
		strcut stat buf;
		struct stat *p = &buf;
		memset(p, 0, sizeof(p));
		// 因为 p 指向一个 struct stat 结构体指针

14:segment fault
	1:memset 引发的错误
		struct stat *buf
		memset(buf, 0, sizeof(buf));
	2:scanf 引发的错误
		char *str;
		scanf("%s", str);

15:使用过的所有头文件
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <math.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <assert.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <sys/resource.h>
	#include <sys/wait.h>
	#include <wait.h>
	#include <memory.h>
	#include <malloc.h>
	#include <signal.h>
	#include <pthread.h>
	#include <semaphore.h>
	#include <sys/ipc.h>
	#include <sys/msg.h>
	#include <sys/shm.h>
	#include <sys/sem.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <netdb.h>
16:signal 原型
	typedef void(*signaler_t)(int);
	// 类型别名: void(*)(int)  --> signaler_t
	void(*signal(signo, void(*func(int))))(int);
	signaler_t signal(int signum, sighandler_t handle);
