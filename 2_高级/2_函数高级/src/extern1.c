/*
 * Copyright (c) 我的有限公司
 * 文件名: extern1.c
 * 描述: 同一个文件中声明/引用外部变量(全局变量)
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

int max(int x, int y)
{
	int result = x > y ? x : y;
	return result;
}

int main(void)
{
	/* 声明/引用变量 a 和 b */
	extern int a,b;
	int result = max(a,b);
	printf("result: %d\n", result);

	return 0;
}

int a = 10, b = 5;
