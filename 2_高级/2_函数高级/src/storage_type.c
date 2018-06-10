/*
 * Copyright (c) 我的有限公司
 * 文件名: storage_type.c
 * 描述: 局部变量,全局变量和变量的存储类型
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

void func();
/* 全局变量(非静态),默认初始化为0 */
int a1;
int *p1;
/* 全局静态变量, 默认初始化为0 */
static int a2;
static int *p2;

int main(void)
{
	printf("a1:%d a2:%d\n", a1, a2);
	printf("p1:%p p2:%p\n", p1, p2);
	a1++;
	a2++;

	func();
	func();
	func();

	return 0;
}

void func()
{
	printf("a1:%d a2:%d\n", a1, a2);
	/* auto 变量, 定义时不初始化会产生一个随机数 */
	int a = 10;
	a++;
	auto int b = 20;
	/* 同 auto, 并且不能定义成 static 和全局的 */
	register int r = 30;
	r++;
	printf("a:%d b:%d r:%d\n", a, b, r);
	/* 默认初始化为0 */
	static int count;
	count++;
	printf("static count: %d\n", count);
}
