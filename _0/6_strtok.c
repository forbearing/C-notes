/*
 * 文件名: strotk.c
 * 描述: 字符串分割函数 strtok 的使用
 * 完成日期: 2018年2月5日20:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char str[] = "hello:iotek:hello:jack";
	int counter = 0;
	char *p = strtok(str, ":");
	while(p != NULL){
		printf("%s\n", p);
		printf("str: %s\n", str);
		counter++;
		p = strtok(NULL, ":");
	}
	printf("\n");
	printf("counter: %d\n", counter);

	return 0;
}
