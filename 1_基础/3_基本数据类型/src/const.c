/* Copyright (c) 我的有限公司
 * 文件名: const.c
 * 描述:只读变量的介绍和使用,只读变量和常量的区别
 * 作者: hyb
 * 日期: 2017年12月16日
 * 版本: 1.0
 */

#include <stdio.h>

#define LENGTH 100

int main(void)
{
	int array[LENGTH];
	const int a = 1;
	int const b = 2;
	printf("a:%d b:%d\n",a,b);

	/* 通过指针修改 const 变量的值 */
	int *p = &a;
	*p = 22;
	printf("a:%d b:%d\n",a,b);

	/* 通过 scanf 函数来修改只读变量的值 */
	printf("please enter a: ");
	scanf("%d", &a);
	printf("a:%d b:%d\n",a,b);

	return 0;
}
