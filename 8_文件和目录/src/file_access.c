/*
 * 文件名: file_access.c
 * 描述: access 函数的使用,判断是否能对指定文件进行某种操作
 * 完成日期: 2018年2月4日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char * argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage : %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int i;
	for(i=1; i<argc; i++){
		if(access(argv[i], F_OK)){
			printf("%s is not exist\n", argv[i]);
			continue;
		}

		if(access(argv[i], R_OK))
			printf("%d can not read %s\n", getpid(), argv[i]);
		else
			printf("%d can read %s\n", getpid(), argv[i]);

		if(access(argv[i], W_OK))
			printf("%d can not write %s\n", getpid(), argv[i]);
		else
			printf("%d can write %s\n", getpid(), argv[i]);

		if(access(argv[i], X_OK))
			printf("%d can not excute %s\n", getpid(), argv[i]);
		else
			printf("%d can excute %s\n", getpid(), argv[i]);
	}

	return 0;
}
