/*
 * Copyright (c) 我的有限公司
 * 文件名: sum_int.c
 * 描述: 函数参数求值顺序和二义性的介绍
 * 完成日期: 2017年12月25日
 * 当前版本: 1.0
 */

#include <stdio.h>

int sum_int(int i, int j);


/*
 * 求值顺序: 
 * 1:如果出现二义性,从右到左
 * 2:如果没有二义性,从左到右
 */
int main(void)
{
	int x = 100, y =20;
	// int var = ++x;
	int s = sum_int(++x, x+y);
	// int s = sum_int(var, x+y);
	printf("s: %d\n",s);

	return 0;
}

int sum_int(int i, int j)
{
	return i + j;
}
