/*
 * 文件名: handle_error.c
 * 描述: 定义专门处理错误信息的宏
 * 完成日期: 2018年2月3日17:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define handle_error(msg) \
	do{ perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		handle_error("open");

	char buf[4096] = {'\0'};
	ssize_t size = sizeof(buf) * sizeof(char);
	while((size = read(fd, buf, size)) > 0){
		if(write(STDOUT_FILENO, buf, size) != size)
			handle_error("write error");
	}
	if(size < 0)
		handle_error("read error");
	if(size == 0)
		printf("\n##### read finished #####\n");

	close(fd);

	return 0;
}
