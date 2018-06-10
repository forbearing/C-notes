/*
 * Copyright (c) 我的有限公司
 * 文件名: arithmetic.c
 * 描述: 算数运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月20日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
/*
	// 除法,取余运算符
	printf("%d %d %d %d\n",8/5,(-8)/5,8/(-5),(-8)/(-5));
	// 余数符号取决于被除数
	printf("%d %d %d %d\n", 8%5, -8%5, 8%-5, -8%-5);
	printf("%d %f\n",1/2,1.0/2);
*/
	// ++ -- 运算符
	int a = 10;
	int b = 20;
	printf("a: %d\n",a++);
	printf("a: %d\n",++a);
	printf("b: %d\n",b--);
	printf("b: %d\n",--b);

	return 0;
}
