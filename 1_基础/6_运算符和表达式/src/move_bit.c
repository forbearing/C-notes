/*
 * Copyright (c) 我的有限公司
 * 文件名: move_bit.c
 * 描述: 移位运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月22日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 算数左移和逻辑左移(正负一样,低位补0,高位丢失) */
	int x = 8;
	int y = -8;
	
	printf("x:%d %#x\n",x << 1, x << 1);
	printf("y:%d %#x\n",y << 1, y << 1);

	/* 采用逻辑右移正负数都是高位补0. 采用算数右移,如符号位1则高位补1反之补0,
	 * 保证正负形式不变. 对于负数到底是采用逻辑右移还是算数右移取决于编译器
	 * (gcc 采用算数右移)
	 */

	printf("x:%d %#x\n", x >> 1, x >> 1);
	printf("y:%d %#x\n", y >> 1, y >> 1);

	return 0;
}
