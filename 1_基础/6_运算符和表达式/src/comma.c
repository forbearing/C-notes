/*
 * Copyright (c) 我的有限公司
 * 文件名: comma.c
 * 描述: 逗号运算符的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月20日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 1;
	int c = 1;
	
	printf("%d %d\n",(a+b,a*b),(a*2,(a+2,a-2)));

	if(a++,b++,c > 0)
		printf("a:%d b:%d c:%d\n",a,b,c);

	int i,j;
	for(i=5,j=-4; i>0,j>0; i--,j--);			// 空语句,里面是逗号表达式
	printf("i:%d j:%d\n",i,j);

	return 0;
}
