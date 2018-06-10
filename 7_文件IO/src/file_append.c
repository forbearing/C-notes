/*
 * 文件名: file_append.c
 * 描述: 文件的原子操作之"文件偏移量调整和文件追加成为原子操作"
 *		 两个程序在不同时间执行相同命令
 * 完成日期: 2018年1月31日14:51
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char*argv[])
{
	if(argc < 3){
		fprintf(stderr,"Usage: %s content destfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//int fd = open(argv[2], O_WRONLY);
	int fd = open(argv[2], O_WRONLY | O_APPEND);
	if(fd < 0){
		perror("open file error");
		exit(EXIT_FAILURE);
	}

	// 不使用 O_APPEND 标志,使用 lseek定位到文件尾部进行追加
	//lseek(fd, 0L, SEEK_END);
	sleep(5);

	// 往文件尾部追加内容
	size_t size = strlen(argv[1]) * sizeof(char);
	if(write(fd, argv[1], size) != size){
		perror("write error");
		exit(EXIT_FAILURE);
	}

	close(fd);

	return 0;
}
