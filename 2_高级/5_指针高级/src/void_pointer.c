/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: void_pointer.c
 * 描述: void指针/通用指针的介绍
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */

#include <stdio.h>
int main(void)
{
	int a = 1;
	char c = 'A';
	/* p 为 void 指针(通用指针) */
	void *p;
	p = &a;
	/* 将 void 指针强制类型转换成整形指针 */
	int *pa = (int*)p;
	printf("a: %d\n", *pa);

	p = &c;
	/* 将 void 指针强制类型转换成字符型指针 */
	char *pc = (char*)p;
	printf("c: %c\n", *pc);

	/* 将任何数据类型的指针赋值给 void 指针 */
	float f = 1.22f;
	float *pf = &f;
	p = pf;
	printf("f: %f\n", *((float*)p));

	return 0;
}
