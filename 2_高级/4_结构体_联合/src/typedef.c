/*
 * Copyright (c) 我的有限公司
 * 文件名: typedef.c
 * 描述: typedef 和 #define 定义类型别名的区别
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */

#include <stdio.h>
#define T_INT int
#define D_PTR_CHAR char*

typedef int t_int;
typedef char* ptr_to_char;

int main(void)
{
	T_INT m = 1, n = 2;
	printf("m:%d n:%d\n", m, n);
	t_int i, j;
	i = 10;
	j = 20;
	size_t k = 23;
	printf("i:%d j:%d k:%ld\n", i, j, k);

	char ch1 = 'a';
	char ch2 = 'b';
	char ch3 = 'c';
	ptr_to_char a, b, c;
	a = &ch1;
	b = &ch2;
	c = &ch3;
	printf("a:%c b:%c c:%c\n", *a, *b, *c);
	//D_PTR_CHAR d,e,f;
	D_PTR_CHAR d;
	D_PTR_CHAR e;
	D_PTR_CHAR f;
	d = &ch1;
	e = &ch2;
	f = &ch3;
	printf("d:%c e:%c f:%c\n", *d, *e, *f);

	return 0;
}
