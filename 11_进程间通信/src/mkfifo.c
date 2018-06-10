/*
 * 文件名:mkfifo.c
 * 描述: mkfifo 系统调用的使用
 * 完成日期: 2018年2月24日 10:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s path\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(mkfifo(argv[1], 0644) < 0){
		perror("mkfifo error");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
