/*
 * Copyright (c) 我的有限公司
 * 文件名称: swap2.c
 * 描述: 函数参数传递之地址传递(指针传递)
 * 作者: hyb
 * 完成日期: 2018年1月1号
 * 当前版本: 1.0
 */

#include <stdio.h>

void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void)
{
	int a, b, *pa, *pb;
	printf("please input two number: ");
	scanf("%d,%d", &a, &b);

	pa = &a;
	pb = &b;
	//if(a < b) swap(pa,pb);
	if(a < b) swap(&a, &b);
	printf("a:%d b:%d\n", a, b);
	printf("*pa:%d *pb:%d\n", *pa, *pb);

	return 0;
}
