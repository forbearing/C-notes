/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_basic.c
 * 描述: 指针的介绍和基本使用
 * 作者: hyb
 * 完成日期: 2017年12月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
int main(void)
{
	int a = 10;
	int *p1 = &a;

	char ch = 'c';
	char *p2 = &ch;

	/* 指针变量占用内存空间大小 */
	printf("p1=>size:%d p2=>size:%d\n", sizeof(p1), sizeof(p2));

	/* 直接访问 */
	a = 20;
	ch = 'C';
	printf("a:%d ch:%c\n", a, ch);
	/* 间接访问 */
	*p1 = 30;
	*p2 = 'A';
	printf("a:%d ch:%c\n", *p1, *p2);
	/* 输出变量的地址 */
	printf("&a:%p &a:%p\n", &a, p1);
	//p1 = (int*)0x12345678;		//不可使用,地址未知
	/* 一个指针只能指向同一数据类型的变量 */
	float *p;
	p = &ch;
	/* NULL 指针(空指针): 表示某个特定的指针目前未指向任何位置 */
	int *p3 = NULL;
	printf("p3:%p %d\n", p3, p3);

	/* 野指针: 指向agiel不确定的内存区域 */
	int *p4;		// 未初始化
	printf("p4: %p\n", p4);

	return 0;
}
