/*
 * 文件名: io.c
 * 描述: 文件IO系统调用函数实现
 * 完成日期: 2018年1月30日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "io.h"

#define BUFFER_LEN 1024

void copy(int fdin, int fdout)
{
	char buffer[BUFFER_LEN];
	ssize_t size;
	while((size = read(fdin, buffer, BUFFER_LEN)) > 0){
		//printf("current: %ld\n", lseek(fdin, 0L, SEEK_CUR));
		if(write(fdout, buffer, size) != size){
			fprintf(stderr, "write error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	//if(size == 0)
	//	printf("### read complete ###\n");
	if(size < 0){
		fprintf(stderr, "read error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
}

extern void set_fl(int fd, int flag)
{
	// 获得原先的文件状态标志
	int val = fcntl(fd, F_GETFL);
	val |= flag;
	// 重新设置文件状态标准(val 为新的文件状态标准)
	if(fcntl(fd, F_SETFL, val) < 0)
		perror("fcntl error");
}
extern void clr_fl(int fd, int flag)
{
	// 获得原先的文件状态标准
	int val = fcntl(fd, F_GETFL);
	val &= ~flag;
	if(fcntl(fd, F_SETFL, val) < 0)
		perror("fcntl error");
}

int lock_reg(int fd, int cmd, 
		short type, off_t offset, short whence, off_t length)
{
	struct flock flock;
	flock.l_type = type;
	flock.l_start = offset;
	flock.l_whence = whence;
	flock.l_len = length;
	//flock.l_pid = getpid();
	//l_pid: 加锁,解锁进程的进程号(pid)
	if(fcntl(fd, cmd, &flock) < 0){
		perror("fcntl error");
		return 0;
	}
	return 1;
}
