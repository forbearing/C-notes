/*
 * Copyright (c) 我的有限公司
 * 文件名: segment_fault.c
 * 描述: 段错误
 * 作者: hyb
 * 完成日期: 2017年12月28日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 操作空指针会出现段错误 */
	int *p1 = NULL;
	//printf("*p1: %d\n", *p1);

	/* 操作野指针可能会出现段错误 */
	//int *p2;
	//printf("*p: %d\n", *p2);
	//*p2 = 100;

	/* 指针指向一个错误的内存地址在使用后会出现段错误 */
	//int *p3 = (int*)0x123ef;
	//printf("*p3: %d\n", *p3);

	/* 数组越界操作 */
	int a[10];
	a[111] = 100;
	printf("%d\n",a[111]);

	return 0;
}
