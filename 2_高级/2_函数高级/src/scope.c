/*
 * Copyright (c) 我的有限公司
 * 文件名: scope.c
 * 描述: 变量的作用域
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

int a = 10;
int b(int c);

int main(void)
{
	int f = 10;
	int g(int h);
	{
		int f = 100, g, i;
		/* 屏蔽掉同名的外部变量 */
		printf("%d\n", f);
	}
	printf("%d\n", a);
	printf("%d\n", f);
	{
		int i;
	}

	return 0;
}
