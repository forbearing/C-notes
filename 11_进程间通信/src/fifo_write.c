/*
 * 文件名: fifo_write.c
 * 描述: 命名管道的创建和写入
 * 完成日期: 2018年2月24日 10:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s fifo\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Open fifo write...\n");
	int fd = open(argv[1], O_WRONLY);
	if(fd < 0)
		handle_error("open error");
	else{
		printf("open fifo success: %d\n", fd);
	}

	char *s = "1234567890";
	ssize_t size = strlen(s);
	if(write(fd, s, size) != size)
		handle_error("write error");

	close(fd);

	return 0;
}
