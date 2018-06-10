/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: gdb_core.c
 * 描述: gdb core 的使用
 * 作者: Hyb
 * 当前日期: 2018年1月21日
 * 当前版本: 1.0
 */

#include <stdio.h>

void func()
{
	int *p = NULL;
	printf("*p: %d\n", *p);
}

int main(void)
{
	func();

	return 0;
}
