/*
 * Copyright (c) 我的有限公司
 * 文件名: extern2_file2.c
 * 描述: 两个文件中声明/引用外部变量(全局变量)
 * 作者: hyb
 * 完成日期: 2018年1月3日
 * 当前版本: 1.0
 */

#include <stdio.h>

extern int a;		// 未重新定义
// int a			// 未重新定义

int power(int n)
{
	//extern int a;	// 未重新定义
	int result = 1;
	int i;
	for(i=1; i<=n; i++)
		result *= a;
	return result;
}
