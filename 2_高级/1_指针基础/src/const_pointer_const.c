/*
 * Copyright (c) 我的有限公司
 * 文件名: const_pointer_const.c
 * 描述: 指向常量的指针常量的介绍和使用
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 指向常量的指针常量
	 * 1:指针本身即地址不可以被修改
	 * 2:通过该指针不可以去修改它所指向的存储单元中的值
	 */
	int a = 3;
	int b = 4;
	int d = 8;
	int const * const cpci = &d;
	//cpci = &a;		// 不可修改
	//*cpci = 5;		// 不可修改
	printf("*cpci:%d\n", *cpci);

	return 0;
}
