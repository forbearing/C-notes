/*
 * Copyright (c) 我的有限公司
 * 文件名: char.c
 * 描述: 字符常量,转义符,字符变量,字符串的介绍和使用
 * 完成日期: 2017年12月16号
 * 版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* 字符常量 */
	printf("%c, %c, %c, %c, %c, %c\n", 'a', 'b', 'A', 'B', '0', '1');
	printf("%d, %d, %d, %d, %d, %d\n", 'a', 'b', 'A', 'B', '0', '1');
	printf("%c, %c, %c, %d, %d, %d\n", 
			'a'+3, 'A'+2, '0'+5, 'a'+3, 'A'+2, '0'+5);
	printf("%d, %d, %c, %c\n", 'a'-'A', '9'-'0', 'c'-32, 'C'+32);

	return 0;
}
