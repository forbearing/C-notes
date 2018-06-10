/*
 * 文件名: chdir.c
 * 描述: 改变文件路径
 * 完成日期: 2018年2月5日22:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char buf[1024];
	memset(buf, 0, sizeof(buf));

	/* 获得当前工作目录 */
	if(getcwd(buf, sizeof(buf)) == NULL)
		handle_error("getcwd error");
	printf("current dir: %s\n", buf);
	/* 切换目录 */
	if(chdir(argv[1]) < 0)
		handle_error("chdir error");
	/* 获得更改后的工作目录 */
	if(getcwd(buf, sizeof(buf)) == NULL)
		handle_error("getcwd error");
	printf("current dir: %s\n", buf);

	return 0;
}
