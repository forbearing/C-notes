/*
 * 文件名: cat.c
 * 描述: cat 命令的实现
 * 完成日期: 2018年2月1日
 */
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd_in = STDIN_FILENO;
	int fd_out = STDOUT_FILENO; 

	if(argc == 1)	copy(fd_in, fd_out);

	int i;
	for(i=1; i<argc; i++){
		fd_in = open(argv[i], O_RDONLY);
		if(fd_in < 0){
			perror("open error");
			continue;
		}
		copy(fd_in, fd_out);
		close(fd_in);
	}

	return 0;
}
