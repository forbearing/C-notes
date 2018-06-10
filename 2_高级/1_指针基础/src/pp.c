/*
 * Copyright (c) 我的有限公司
 * 文件名: pp.c
 * 描述: 二级指针的介绍和使用
 * 作者: hyb
 * 完成日期: 2018年1月2日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int a = 10;
	int *p = &a;
	int **pp = &p;

	printf("p:%p *p:%d\n", p, *p);
	printf("pp:%p **p:%d %d\n", pp, **pp, *(*pp));

	printf("pp=&p:%d\n", pp == &p);
	printf("*pp==p:%d *pp==&a:%d\n", *pp==p, *pp==&a);
	printf("**pp=*p:%d **pp==a:%d\n",**pp=*p, **pp=a);
	printf("*(&p)==p:%d\n",*(&p)==p);

	return 0;
}
