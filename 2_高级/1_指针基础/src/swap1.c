/*
 * Copyright (c) 我的有限公司
 * 文件名: swap1.c
 * 描述: 函数参数传递之值传递
 * 作者: hyb
 * 完成日期: 2018年1月1号
 * 当前版本: 1.0
 */

#include <stdio.h>

 void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("x:%d y:%d\n", x, y);
}

int main(void)
{
	int a, b;
	printf("please input two number: ");
	scanf("%d,%d", &a, &b);
	if(a < b) swap(a,b);
	printf("a:%d b:%d\n", a, b);

	return 0;
}
