/*
 * 文件名: filetype.c
 * 描述: 分析文件类型,stat/fstat/lstat 函数的介绍和使用
 * 完成日期: 2018年2月4日10:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <memory.h>

#define handle_error(msg)	\
	do{ perror(msg); continue; } while(0)

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int i;
	struct stat buf;
	for(i=1; i<argc; i++){
		memset(&buf, 0, sizeof(buf));
		if(lstat(argv[i], &buf) < 0)
			handle_error("lstat error");
		printf("%-20s", argv[i]);
		/* 判断文件类型 */
		if(S_ISREG(buf.st_mode))
			printf("Normal file");
		else if(S_ISDIR(buf.st_mode))
			printf("Direcotry");
		else if(S_ISLNK(buf.st_mode))
			printf("Symbol link");
		else if(S_ISCHR(buf.st_mode))
			printf("Character special file");
		else if(S_ISBLK(buf.st_mode))
			printf("Block special file");
		else if(S_ISFIFO(buf.st_mode))
			printf("FIFO, named pipe");
		else if(S_ISSOCK(buf.st_mode))
			printf("Socket");
		else
			printf("Unknow file type");
		printf("\n");
	}

	return 0;
}
