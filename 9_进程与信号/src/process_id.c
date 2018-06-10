/*
 * 文件名: process_id.c
 * 描述: 进程标志的介绍和相关函数的使用
 * 完成日期: 2018年2月8号10:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("pid: %d\n", getpid());
	printf("uid: %d\n", getuid());
	printf("euid: %d\n", geteuid());
	printf("user gid: %d\n", getgid());
	printf("ppid: %d\n", getppid());
	printf("process gid: %d\n", getpgrp());
	printf("process gid: %d\n", getpgid(getpid()));
	printf("ppgid: %d\n", getpgid(getppid()));

	return 0;
}
