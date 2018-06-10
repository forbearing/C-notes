/*
 * Copyright (c) 我的有限公司
 * 文件名: math.c
 * 描述: 函数自定义的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

/*
 * 函数名称: add
 * 描述: 输出两个数进行累计后将结果返回
 * 作者: hyb
 * 完成日期: 2017年12月23日
 * 输入: 两个整数 i 和 j
 * 返回: 整型的累加和
 * 当前版本: 1.0
 */

int add(int i, int j)
{
	return i+j;
}

int sub(int i, int j)
{
	return i - j;
}

int mul(int i, int j)
{
	return i * j;
}

int div(int i, int j)
{
	return i / j;
}

void out(int i, int j)
{
	printf("add():%d\n",add(i,j));		// 函数的嵌套调用
}

int main(void)
{
	int i,j;
	printf("please input i and j: ");
	scanf("%d %d", &i, &j);

	int result = add(i,j);
	printf("add result: %d\n",result);
	result = sub(i,j);
	printf("sub result: %d\n",result);
	result = mul(i,j);
	printf("mul result: %d\n",result);
	result = div(i,j);
	printf("div result: %d\n",result);

	out (i,j)

	return 0;
}
