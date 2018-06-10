/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: union.c
 * 描述: 联合的基本使用
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	union U
	{
		int a;
		float b;
		char c;
	} u={10};
	printf("a:%d b:%f c:%c\n", u.a, u.b, u.c);
	u.b = 3.5f;
	printf("a:%d b:%f c:%c\n", u.a, u.b, u.c);
	u.c = 'x';
	printf("a:%d b:%f c:%c\n", u.a, u.b, u.c);

	return 0;
}
