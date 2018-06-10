/*
 * Copryright (c) 2018 我的有限公司
 * 文件名: macro2.c
 * 描述: 带参宏定义
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main(void)
{
	int a = 5;
	printf("SQUARE(a): %d\n", SQUARE(a));
	printf("SQUARE(a + 1): %d\n", SQUARE(a + 1));
	printf("10/SQUARE(a): %d\n", 10/SQUARE(a));

	return 0;
}
