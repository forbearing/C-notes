/*
 * Copyright (c) 我的有限公司
 * 文件名: rotate.c
 * 描述: 将16位数字分别左旋转和右旋转4位
 * 作者: hyb
 * 完成日期: 2017年12月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

/* num = 0x2345, n = 4 ==> num = 0x5234 */
unsigned short int rotate16Left(unsigned short int num, int n)
{
	//return (num >> n) | (num << (sizeof(short) - n));
	//return (num >> n) | (num << (sizeof(num) - n));
	return (num >> n) | (num << (16 - n));
}

/* num = 0x2345, n = 4 --> num = 0x3452 */
unsigned short int rotate16Right(unsigned short int num, int n)
{
	return (num << n) | (num >> (16 - n));
}

int main(void)
{
	unsigned short int num = 0x2345;
	printf("Original: %#x\n",num);
	printf("Rotated Left: %#x\n",rotate16Left(num,4));
	printf("Rotated Right: %#x\n",rotate16Right(num,4));

	return 0;
}
