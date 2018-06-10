/*
 * 文件名: file_softlink.c
 * 描述: 软链接的创建
 * 完成日期: 2018年2月5日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s srcfile linkfiles\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 对源文件创建符号链接 */
	if(symlink(argv[1], argv[2]) < 0)
		handle_error("symlink error");

	char buffer[1024];
	ssize_t size;
	memset(buffer, 0, sizeof(buffer));
	int fd = open(argv[2], O_RDONLY);
	if(fd < 0)
		handle_error("open error");

	/* 读取软链接文件引用的源文件内容 */
	if((size = read(fd, buffer, sizeof(buffer))) < 0)
		handle_error("read error");
	else
		write(STDOUT_FILENO, buffer, size);
	printf("\n");
	close(fd);

	/* 读取软链接文件本身的内容 */
	memset(buffer, 0, sizeof(buffer));
	if((size = readlink(argv[2], buffer, sizeof(buffer))) < 0)
		handle_error("readlink error");
	else
		write(STDOUT_FILENO, buffer, size);
	printf("\n");


	return 0;
}
