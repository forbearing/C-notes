/*
 * Copyright (c) 我的有限公司
 * 文件名: printf.c
 * 描述: printf 函数的介绍和使用
 * 日期: 2017年12月16日
 * 版本: 1.0
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	/* printf 函数 */
	int x =10;
	float y = 20.55f;
	double z = 33.343;
	long double w = 44.322l;
	char ch = 'a';
	char str[] = "Hello Linux";
	printf("%05d %u %o %#x %#X\n",6553,x,x,x,x);
	printf("%.2f %e %E\n",y,y,y);
	printf("%c\n",ch);
	printf("%30s\n",str);
	printf("%d%%\n",x);
	printf("%d\n",20,30);
	printf("%Lf\n",w);
	printf("--------------------------------------------\n");

	return 0;
}
