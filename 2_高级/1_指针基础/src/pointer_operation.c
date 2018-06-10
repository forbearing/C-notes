/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_operation.c
 * 描述: 指针的运算
 * 作者: hyb
 * 完成日期: 2017年12月28日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
/*	int a = 10;
	int *p1 = &a;
	int *p2;
	p2 = p1;
	printf("a: %d %d\n", *p1, *p2);
*/
	/* 左值 和 右值 */
/*	int *p = &a;
	*p = *p + 1;
	printf("a: %d %d\n", *p, a);
*/
	/* 数组直接赋值 */
/*	int aa[5] = {1,2,3,4,5};
	int bb[5] = {5,4,3,2,1};
	aa = bb;
*/
	/* 指针的加减操作 */
/*	int a[] = {1,2,3,4,5};
	int *p = a;
	++p;
	printf("*p: %d\n", *p);
	p++;
	printf("*p: %d\n", *p);
	--p;
	printf("*p: %d\n", *p);
	p--;
	printf("*p: %d\n", *p);

	p = a;
	p = p + 4;
	printf("*p: %d\n", *p);
	p = p -2;
	printf("*p: %d\n", *p);
*/
/*	int a[] = {1,2,3,4,5};
	int *p = a;
	printf("++(*p):%d\n", ++(*p));
	printf("(*p)++:%d\n", (*p)++);
	// 元素的值被修改
	printf("a[0]:%d\n",a[0]);

	// 先取元素的值,再指针作加1操作
	printf("*p++:%d\n", *p++);
	printf("*(p++):%d\n", *(p++));
	printf("*p: %d\n", *p);
*/
	int a[] = {1,2,3,4,5};
	int *p = a;
	int *p2 = a + 4;
	printf("p < p2:%d p <= p2:%d\n", p < p2, p <= p2);
	printf("p == p2:%d p != p2:%d\n", p == p2-4, p != p2);
	printf("p == NULL:%d\n", p == NULL);
	printf("p2 - p:%d\n", p2 - p);

	return 0;
}
