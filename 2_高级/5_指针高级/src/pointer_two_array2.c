/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: pointer_two_array2.c
 * 描述: 指针和二维数组的遍历
 * 作者: Hyb
 * 完成日期: 2018年1月17日
 * 当期版本: 1.0
 */

#include <stdio.h>

void out1(int a[][4], int size);
void out2(int *p, int size);		// p 为指向某行某列元素的指针(列指针)
void out3(int (*p)[4], int row, int col);	// p 为数组指针(行指针),指向的是行

int main(void)
{
	int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	out1(a, 12);					// 实参是数组名,型参是数组名
	printf("\n***************************\n");

	out2(*a, 12);					// 实参和型参都是列指针
	printf("\n***************************\n");

	/* 定义一个数组指针或称为行指针,指向的是行(包含4个元素的一维数组) */
	int (*p)[4];
	p = a;							// 指向第一行
	out3(p, 3, 4);					// 实参是指针,形参是指针(必须是数组指针)
	printf("\n***************************\n");
	out3(a, 3, 4);					// 同上
	printf("\n***************************\n");

	return 0;
}

void out1(int a[][4], int size)
{
	int *p;			// p 为指向某行某列元素的指针
	for(p=a[0]; p<a[0]+size; p++){
		if((p - a[0]) % 4 == 0)
			printf("\n");
		printf("%d ", *p);
	}
}

void out2(int *p, int size)
{
	int *s;
	for(s=p; s<p+size; s++){
		if((s - p) % 4 == 0)
			printf("\n");
		printf("%d ", *s);
	}
}

void out3(int (*p)[4], int row, int col)
{
	int i, j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
}
