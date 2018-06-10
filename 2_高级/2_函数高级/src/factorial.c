/*
 * Copyright (c) 我的有限公司
 * 文件名: factorial.c
 * 描述: 数的阶乘
 * 作者: hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>

long factorial1(int n);
long factorial2(int n);

int main(void)
{
	int n = 8;
	printf("factorial1(int n): %ld\n", factorial1(8));
	printf("factorial2(int n): %ld\n", factorial2(8));

	return 0;
}

long factorial1(int n)
{
	if(n <= 0)
		return 1;
	else
		return n * factorial1(n-1);
}

long factorial2(int n)
{
	int result = 1; 
	while(n > 1){
		result *= n;
		n -=1;
	}
	return result;
}
