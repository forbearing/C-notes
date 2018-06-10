/*
 * Copyright (c) 我的有限公司
 * 文件名: triangle.c
 * 描述: 根据三条边大小求三角形面积
 * 作者: hyb
 * 日期: 2017年12月16日
 * 版本: 1.0
 */

#include <stdio.h>
#include <math.h>
/* gcc -o bin/triangle src/triangle.c -lm */

int main(void)
{
	float a, b, c, s, area;
	printf("side of triangle: ");
	scanf("%f%f%f", &a, &b, &c);

	/* 判断输入的三条边是否能够构成三角形 */
	if(a + b <= c || a + c <= b || b + c <= a){
		printf("input size of triangle error\n");
		return 1;
	}
	
	s = (a + b + c) / 2.0;		// 2.0而不是2,否则结果会去整
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("triangle area: %f\n",area);

	return 0;
}
