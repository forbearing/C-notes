/*
 * 文件名: softlink.c
 * 描述: symlink 和 readlink 函数的使用
 * 完成日期: 2018年2月5日11:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{

	if(argc < 3){
		fprintf(stderr, "Usage: %s srcfile desfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 创建软链接 */
	if(symlink(argv[1], argv[2]) < 0)
		handle_error("symlink error");

	/* 读取软链接文件指向的源文件内容 */
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
		handle_error("open error");
	char buf[BUFFER_SIZE];
	ssize_t size;
	memset(buf, 0, sizeof(buf));
	if((size = read(fd, buf, sizeof(buf))) < 0)
		handle_error("read error");
	else
		write(STDOUT_FILENO, buf, size);
	printf("\n");
	close(fd);

	/* 读取软链接本身的内容 */
	memset(buf, 0, sizeof(buf));
	if((size = readlink(argv[2], buf, sizeof(buf))) < 0)
		handle_error("readlink error");
	else
		write(STDOUT_FILENO, buf, size);
	printf("\n");

	return 0;
}
