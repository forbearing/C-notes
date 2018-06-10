/*
 * 文件名: hole_file.c
 * 描述: 利用 lseek 函数实现空洞文件
 * 完成日期: 2018年1月31日凌晨1:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* 生成空洞文件 */
char *buffer = "0123456789";

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "-usage: %s [file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fd < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	/* 第一次写入 */
	size_t size = strlen(buffer) * sizeof(char);
	if(write(fd, buffer, size) != size){
		perror("write error");
		exit(EXIT_FAILURE);
	}

	/* 定位到文件尾部并跳过10个字节 */
	if(lseek(fd, 10L, SEEK_END) < 0){
		perror("lseek error");
		exit(EXIT_FAILURE);
	}

	/* 第二次写入 */
	if(write(fd, buffer, size) != size){
		perror("write error");
		exit(EXIT_FAILURE);
	}

	close(fd);

	return 0;
}
