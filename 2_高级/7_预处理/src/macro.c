/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: macro.c
 * 描述: 无参宏定义
 * 作者: Hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

#define YES 1
#define NO 0
#define OUT printf("hello linux\n")
#define WIDTH 80
#define LENGTH (WIDTH+40)
#define NAME "Hyb"

/*
#undef YES
#undef NO
#undef PI
#undef OUT
*/

#define DEBUG_PRINT  printf("File %s line %d: " \
						"x=%d, y=%d, z=%d\n", \
						__FILE__, __LINE__, \
						x, y, z)

int main(void)
{
	printf("%d %d\n", YES, NO);
	OUT;

	int result = LENGTH * 2;
	printf("result: %d\n", result);
	int x = 1;
	int y = 2;
	int z = x + y;
	DEBUG_PRINT;

	return 0;
}
