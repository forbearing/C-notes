/*
 * 文件名: add.c
 * 描述: 协同进程
 *		父进程从管道a 中传入x 和y, 子进程从管道a 中获取x 和y 并计算之和
 *		子进程从管道b 中传入x h y, 父进程从管道b 中获取x+y 的结果并输出
 * 完成日期: 2018年2月24日 13:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	int x, y;
	if(read(STDIN_FILENO, &x, sizeof(int)) < 0)
		handle_error("read error");
	if(read(STDIN_FILENO, &y, sizeof(int)) < 0)
		handle_error("read error");
	int result = x + y;

	if(write(STDOUT_FILENO, &result, sizeof(int)) != sizeof(int))
		handle_error("write error");

	return 0;
}
