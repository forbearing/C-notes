/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: strcpy_test.c
 * 描述: 字符串拷贝函数的陷阱介绍
 * 作者: Hyb
 * 完成日期: 2018年1月7日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p = "iotek";
	char str[20] = "jack";
	char *ap = strcpy(str, "zhangsan");
	//char *ap = strcpy(p, "zhangsan");			//segementation fault
	//char *ap = strcpy(NULL, "zhangsan");		//segementation fault
	//char *ap = strcpy("hello", "zhangsan");	//segementation fault
	printf("ap:%s\n", ap);
	//printf("str:%s\n", str);

	return 0;
}
