/*
 * 文件名: cp.c
 * 描述: io.h 和 io.c 的调用程序, 文件复制功能
 * 完成日期: 2018年1月31日凌晨1:00
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "io.h"

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: %s srcfile destfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int fdin, fdout;
	// 打开一个待读取的文件
	fdin = open(argv[1], O_RDONLY);
	if(fdin < 0){
		fprintf(stderr,"open erro: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}else{
		printf("open file: %d\n", fdin);
	}
	// 打开一个待写入的文件
	// O_TRUNC 可省略
	fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if(fdout < 0){
		fprintf(stderr, "open error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}else{
		printf("write file: %d\n", fdout);
	}

	// 文件复制
	copy(fdin, fdout);

	// 关闭文件
	close(fdin);
	close(fdout);

	return 0;
}
