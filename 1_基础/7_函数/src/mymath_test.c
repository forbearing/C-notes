/*
 * Copyright (c) 我的有限公司
 * 文件名: mymath_test.c
 * 描述: 程序的入口, 负责调用加减乘除函数
 * 作者: hyb
 * 完成日期: 2017年12月23日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "mymath.h"

int main(void)
{
	int i, j;
	printf("please enter i and j: ");
	scanf("%d %d", &i, &j);
	int result = add(i,j);
	printf("add result: %d\n", result);
	result = sub(i,j);
	printf("sub result: %d\n", result);
	result = mul(i,j);
	printf("mul result: %d\n", result);
	result = div(i,j);
	printf("div result: %d\n", result);

	return 0;
}
