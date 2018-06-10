/*
 * Copyright (c) 我的有限公司
 * 文件名: average.c
 * 描述: 利用可变参数列表统计一组数的平均值
 * 作者: hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdarg.h>

float average(int n_values, ...);
float average2(int n_values, ...);

int main(void)
{
	float aver = average(5, 1, 2, 3, 4, 5);
	printf("aver: %.2f\n", aver);
	aver = average2(5, 1, 2, 3, 4, 5);
	printf("aver: %.2f\n", aver);

	return 0;
}

float average(int n_values, ...)
{
	/* 定义一个 va_list 类型的变量用于访问可变参数列表 */
	va_list  var_arg;
	int count;
	float sum = 0;
	
	/* 初始化可变参数列表 */
	va_start(var_arg, n_values);

	/* 通过循环获取可变参数列表中的参数 */
	for(count=0; count<n_values; count++){
		//int 为可变参数类型
		sum += va_arg(var_arg, int);
	}

	/* 关闭初始化列表 */
	va_end(var_arg);

	return sum / n_values;
}

float average2(int n_values, ...)
{
	int *p = &n_values;
	float sum = 0.0f;
	int i;
	for(i=1; i<=n_values; i++)
		sum += *(p+i);
	
	return sum / n_values;
}
