/*
 * Copyright (c) 我的有限公司
 * 文件名: extern2_file1.c
 * 描述: 两个文件中声明/引用外部变量(全局变量)
 * 作者: hyb
 * 完成日期: 2018年1月3日
 * 当前版本: 1.0
 */

#include <stdio.h>

int power(int);
int a = 2;

int main(void)
{
	int result = power(5);
	printf("result: %d\n", result);
}
