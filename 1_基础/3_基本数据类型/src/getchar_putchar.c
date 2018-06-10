/*
 * Copyright (c) 我的有限公司
 * 文件名: getchar_putchar.c
 * 描述: getchar 和 putchar 函数的结束和使用
 * 作者: hyb
 * 完成日期: 2017年12月17日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* getchar 函数 */
	int c;
	printf("please input a character: ");
	c = getchar();

	/* putchar 函数 */
	putchar(c);
	putchar('\n');

	return 0;
}
