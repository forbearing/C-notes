/*
 * 文件名: file_hardlink.c
 * 描述: 创建硬链接
 * 完成日期: 2018年2月5日10:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define handle_error(msg)	\
	do { perror(msg); continue; } while(0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s srcfile files\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int i;
	for(i=2; i<argc; i++){
		if(link(argv[1], argv[i]) < 0)
			handle_error("link error");
	}
	printf("create success\n");

	return 0;
}
