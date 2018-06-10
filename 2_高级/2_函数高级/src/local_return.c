/*
 * Copyright (c) 我的有限公司
 * 文件名: local_return.c
 * 描述: 指针函数和局部变量返回
 * 作者: hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <unistd.h>

int fun(int n)
{
	int sum = 0;
	int i;
	for(i=1; i<=n; i++)
		sum += i;
	return sum;
}

/* 返回一个整型指针 */
int *fun2(int n)
{
	//static int sum = 0;
	int sum = 0;
	int *p = &sum;
	int i;
	for(i=1; i<=n; i++)
		sum += i;
	return p;
	//return &sum;		// 会出现警告
}

int main(void)
{
	int sum = fun(100);
	printf("sum: %d\n", sum);
	int *p_sum = fun2(100);
	sleep(1);
	printf("sum: %d\n", *p_sum);

	return 0;
}
