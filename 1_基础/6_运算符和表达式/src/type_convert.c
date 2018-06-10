/*
 * Copyright (c) 我的有限公司
 * 文件名: type_convert.c
 * 描述: 类型转换的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月20日22:21分
 * 当前版本: 1.0
 */

#include <stdio.h>

int a(float i, float j)
{
	return i + j;
}

int main(void)
{
	long x = 100;					// 隐式转换

	float i = 4.6f;
	float j = 4.3f;

	float var = (int)i + (int)j;	// 显示转换
	printf("var = %f\n",var);

	int k = 20.55;					// 精度丢失
	printf("result: %f\n",k+i+j+10+'a');		// 结果为精度最高的类型

	int result = a(10,20);
	printf("result: %d\n",result);


	return 0;
}
