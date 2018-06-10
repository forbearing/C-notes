/*
 * 文件名: file_umask.c
 * 描述: umask 函数的介绍和使用
 * 完成日期: 2018年2月4日11:53
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MODE S_IRWXU | S_IRWXG | S_IRWXO
#define UMASK S_IXUSR | S_IWGRP | S_IXGRP | S_IRWXO

int main(int argc, char * argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// 设置掩码
	umask(UMASK);
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, MODE);
	if(fd < 0){
		perror("open file error");
		exit(EXIT_FAILURE);
	}

	close(fd);

	return 0;
}
