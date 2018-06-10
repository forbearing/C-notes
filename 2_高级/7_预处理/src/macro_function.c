/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: macro_function.c
 * 描述: 带参宏定义和函数区别
 * 作者: Hyb
 * 完成日期: 2018年1月26日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <malloc.h>

#define MAX(a,b)	((a) > (b) ? (a) : (b))
#define MALLOC(n,type)	\
	((type*)malloc((n) * sizeof(type)))

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)	
{
	int a = 1;
	int b = 2;
	//printf("max(a,b):%d\n", max(a++,b++));
	printf("MAX(a,b):%d\n", MAX(a++,b++));
	printf("a:%d b:%d\n", a, b);

	double c = 3.5;
	double d = 4.5;
	printf("max(a,b):%.2lf\n", (float)max(c,d));			// 隐式转换
	printf("MAX(a,b):%.2lf\n", MAX(c,d));

	int *ptr = NULL;
	ptr = MALLOC(10, int);
	//ptr = ((int*)malloc((10) * sizeof(int)));
	printf("ptr:%p\n", ptr);
	free(ptr);
	ptr = NULL;

	return 0;
}
