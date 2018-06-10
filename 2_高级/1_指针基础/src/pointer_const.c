/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_const.c
 * 描述: 指针常量的介绍和使用
 * 完成日期: 2018年1月1日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 指针常量
	 * 1:指针本身即地址不可以被修改
	 * 2:通过该指针可以修改它所指向的存储单元中的值
	 */
	int a = 3;
	int b = 4;

	int * const cpi = &b;
	//cpi  = &a;	//不可修改
	*cpi = 5;
	printf("b:%d *cpi:%d\n", b, *cpi);

	int c = 6;
	int **pp = &cpi;
	// 通过二级指针还是可以修改指针常量
	*pp = &c;
	printf("*cpi:%d\n", *cpi);

	return 0;
}
