/*
 * Copyright (c) 我的有限公司
 * 文件名: stack_test.c
 * 描述: 栈操作调用程序
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "stack.h"

int main(void)
{
	push(10);
	push(11);
	push(12);
	push(13);
	printf("popup is: %d\n", popup());
	printf("popup is: %d\n", popup());
	printf("top is: %d\n", top());

	push(14);
	printf("popup is: %d\n", popup());
	printf("popup is: %d\n", popup());
	printf("popup is: %d\n", popup());
	printf("popup is: %d\n", popup());

	return 0;
}
