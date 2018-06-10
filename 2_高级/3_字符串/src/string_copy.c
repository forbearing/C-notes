/*
 * Copyright (c) 2018 我的有限公司 * 文件名: string_cpoy.c
 * 描述: 不使用库函数完成字符串的复制
 * 作者: Hyb
 * 完成日期: 2018年1月7日
 * 当前版本: 1.0
 */

#include <stdio.h>

char *my_strcpy(char* to, char *from);

int main(void)
{
	char *from = "hello iotek";
	char to[30];

	char *p = my_strcpy(to, from);
	printf("%s, %s\n", p, to);

	return 0;
}

char *my_strcpy(char *to, char *from)
{
	if(to == NULL || from == NULL)
		return NULL;
	char *p = to;
	for(; *from != '\0'; from++,to++)
		*to = *from;
	*to='\0';
	return p;
}
