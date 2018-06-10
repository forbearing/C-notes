/*
 * Copyright (c) 我的有限公司
 * 文件名: recursion.c
 * 描述: 通过递归调用将一个十进制整数转换成字符后输出
 * 作者: hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>

void binary_to_ascii(unsigned int value)
{
	unsigned int temp;
	temp = value / 10;
	if(temp != 0)
		binary_to_ascii(temp);
	putchar(value % 10 + '0');
}

int main(void)
{
	binary_to_ascii(4267);
	printf("\n");

	return 0;
}
