/*
 * Copyright (c) 我的有限公司
 * 文件名: fibonacci.c
 * 描述: 斐波那契数: 一个数列,数列中每个数的值是它前面两个数的和
 * 作者: Hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>

long fibonacci1(int n);
long fibonacci2(int n);

int main(void)
{
	int n = 10;
	int i;
	for(i=1; i<=n; i++)
		printf("%ld", fibonacci1(i));
	printf("\n");

	for(i=1; i<=n; i++)
		printf("%ld", fibonacci2(i));
	printf("\n");

	return 0;
}

long fibonacci1(int n)
{
	if(n <= 2)
		return 1;
	return fibonacci1(n-1) + fibonacci1(n-2);
}

long fibonacci2(int n)
{
	long result;
	long previous_result;
	long next_older_result;

	result = previous_result = 1;
	while (n > 2){
		n -= 1;
		next_older_result = previous_result;
		previous_result = result;
		result = previous_result + next_older_result;
	}
	return result;
}
