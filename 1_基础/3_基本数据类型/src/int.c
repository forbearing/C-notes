/*
 * Copyright (c) 我的有限公司
 * 文件名: int.c
 * 描述: 打印各类整型的长度
 * 日期: 2017年12月17号
 * 版本: 1.0
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("int: %ld\n",sizeof(int));
	printf("short: %ld\n",sizeof(short));
	printf("long: %ld\n",sizeof(long));
	printf("long long: %ld\n",sizeof(long long));

	printf("float: %ld\n", sizeof(float));
	printf("double: %ld\n",sizeof(double));
	printf("long double: %ld\n",sizeof(long double));

	/* 编译通过,会溢出 */
	signed short int m = 32768;
	unsigned short int n = -1;
	printf("m:%hd n:%d\n",m,n);

	long l = 32L;		// 加上'L',否则会编程 int 类型
	unsigned long ul = 32ul;
	int i = 0332;
	int j = 0x32a;
	printf("i: %d, j: %d\n",i,j);

	return 0;
}
