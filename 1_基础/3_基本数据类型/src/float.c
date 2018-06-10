/*
 * Copyright (c) 我的有限公司
 * 文件名: float.c
 * 描述: 浮点型常量,浮点型变量的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月16日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	double x = 10.8888888;
	long double d = 1e4L;
	float f = 3.1455556F;
	float f2 = 5.5555556;	// 隐式类型转换, double -> float, 可能会导致精度丢失
	float f3 = 5.3e2;
	float f4 = 5E2;
	float f5 = 5.;
	float f6 = .6;
	float f7 = 10;
	
	printf("float:%d double:%d long double:%d\n",
			sizeof(float),sizeof(double),sizeof(long double));
	printf("f3:%f f4:%f f5:%f f6:%f f7:%f\n",f3,f4,f5,f6,f7);
	printf("long double d: %Lf\n",d);
	printf("double x: %lf\n",x);
	printf("float f: %.2f\n",f);
	printf("float f2: %5.2f\n",f2);

	return 0;
}
