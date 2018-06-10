/*
 * 文件名: nonblock_read.c
 * 描述: 非阻塞的从键盘读入(read 函数默认为阻塞的)
 *		gcc -o bin/nonblock_read src/nonblock_read.c src/io.c -Iinclude
 *		Ctrl-D: 表示读到文件末尾
 * 完成日期: 2018年2月1日23:40
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "io.h"

int main(void)
{
	char buffer[4096] = {'\0'};
	ssize_t size = 0;

	/* 设置非阻塞 IO */
	set_fl(STDIN_FILENO, O_NONBLOCK);

	sleep(5);

	size = read(STDIN_FILENO, buffer, sizeof(buffer));
	if(size < 0){
		perror("read error");
		exit(EXIT_FAILURE);
	}else if(size == 0){
		printf("read finished\n");
	}else{
		if(write(STDOUT_FILENO, buffer, size) != size){
			perror("write error");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}
