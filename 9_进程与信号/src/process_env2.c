/*
 * 文件名: process_env2.c
 * 描述: 环境表的介绍和使用
 * 完成日期: 2018年2月6日18:40
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

void show_env()
{
	int i = 0;
	char * env;
	while((env = environ[i]) != NULL){
		printf("%s\n", env);
		i++;
	}
}

int main(void)
{
	show_env();
	printf("------------------------------------\n");

	putenv("NAME=Hyb");
	setenv("Country", "China", 0);
	show_env();
	printf("------------------------------------\n");

	unsetenv("Country");
	show_env();

	return 0;
}
