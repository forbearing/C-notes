/*
 * 文件名: file_truncate.c
 * 描述: truncate 和 ftruncate 函数的使用
 * 完成日期: 2018年2月4日13:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

long get_len(int fd);

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s file length\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if(access(argv[1], F_OK) < 0)
		handle_error("file not exist");
	else if(access(argv[1], W_OK) < 0)
		handle_error("write permission error");

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		handle_error("open file error");

	long len = get_len(fd);
	printf("file \"%s\" length: %ld\n", argv[1], len);


	/* 将文件长度截短为指定长度 */
	if(truncate(argv[1], atoi(argv[2])) < 0)
		handle_error("truncate error");

	len = get_len(fd);
	printf("after truncate length: %ld\n", len);

	close(fd);

	return 0;
}

long get_len(int fd)
{
	int len = lseek(fd, 0L, SEEK_END);
	if(len < 0)
		return -1;
	return len;
}
