/*
 * 文件名: process_env.c
 * 描述: 环境表的介绍和使用
 * 完成日期: 2018年2月6日
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
	int i = 0;
	char *env;
	while((env = envp[i]) != NULL){
		printf("%s\n", env);
		i++;
	}

	return 0;
}
