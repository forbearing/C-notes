/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_one_array.c
 * 描述: 指针和一维数组的使用
 * 作者: hyb
 * 完成日期: 2018年1月1号
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	printf("\033[2J");		// 清屏
	int a[] = {1,2,3,4,5};
	int *p = a;

	printf("a:%p &a[0]:%p p:%p\n", a, &a[0], p);

	a[1] = 2;
	*(a + 2) = 20;
	p[3] = 100;
	*(p + 4) = 200;
	*(p + 5) = 500;			// 数组越界操作

	int i;
	for(i=0; i<5; i++){
		printf("%d", a[i]);		// 下标法
	}
	printf("\n****************************\n");
	for(i=0; i<5; i++){
		printf("%d", *(a+i));	// 指针法
	}
	printf("\n****************************\n");
	for(i=0; i<5; i++){
		printf("%d", *(p+i));	// 指针法
	}
	printf("\n");

	return 0;
}
