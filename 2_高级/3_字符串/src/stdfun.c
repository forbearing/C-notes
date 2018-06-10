/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: stdfun.c
 * 描述: 常见的C标准库函数介绍
 * 作者: hyb
 * 完成日期: 2018年1月8日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int a = -1;
	printf("abs(a):%d\n", abs(-1));

	char *b = "10";
	char *c = "20";
	int d = atoi(b) + atoi(c);
	printf("d:%d\n", d);

	double f = sin(0.5);
	printf("f: %lf\n", f);

	double g = exp(3.0);
	printf("g:%lf\n", g);

	double h = pow(3.0, 3);
	printf("h:%lf\n", h);
	
	int i = sqrt(16);
	printf("i:%d\n", i);

	double j = floor(1.6);
	printf("j: %lf\n", j);

	double k = ceil(1.2);
	printf("k: %lf\n", k);

	double l = trunc(1.5);
	double m = round(1.5);
	printf("l:%lf m:%lf\n", l, m);

	printf("------------------------------------\n");
	for(i=0; i<10; i++){
		srand((unsigned)time(NULL)+i);
		printf("rand():%d\n", rand());
	}

	printf("------------------------------------\n");
	for(i=0; i<10; i++)
		printf("drand48():%f\n", drand48());

	printf("------------------------------------\n");
	time_t current;
	time(&current);
	printf("current time: %s\n", ctime(&current));

	return 0;
}
