/*
 * Copyright (c) 我的有限公司
 * 文件名: condition.c
 * 描述: 条件运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int a,b,max;
	printf("please input two numbers: \n");
	scanf("%d %d", &a, &b);
	//a > b ? max = a : max = b;
	max = a > b ? a : b;
	printf("max = %d\n",max);

	return 0;
}
