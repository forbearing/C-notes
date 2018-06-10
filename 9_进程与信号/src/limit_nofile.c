/*
 * 文件名: limit_nofile.c
 * 描述: 进程资源限制, setlimit 的使用
 * 完成日期: 2018年2月5日9:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/resource.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)
#define MODE S_IRWXU | S_IRWXG | S_IRWXO

int open_file(const char *filename){
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, MODE);
	if(fd < 0)
		handle_error("open error");
	return fd;
}

int main(int argc, char *argv[])
{
	struct rlimit limit;
	limit.rlim_cur = 4;				// 设置软资源限制
	limit.rlim_max = 1024;			// 设置硬资源限制

	/* 设置文件打开的最大数 */
	if(setrlimit(RLIMIT_NOFILE, &limit) < 0)
		handle_error("setrlimit error");


	/* 打开文件 */
	int fd1, fd2;
	fd1 = open_file("f1.txt");
	fd2 = open_file("f2.txt");

	close(fd1);
	close(fd2);

	return 0;
}
