/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_one_array2.c
 * 描述: 数组的传参方式
 * 作者: hyb
 * 完成日期: 2018年1月2号
 * 当前版本: 1.0
 */

#include <stdio.h>

void print_array1(int array[], int size);
void print_arrya2(int *ap, int size);

int main(void)
{
	int a[] = {1,2,3,4,5};
	int *p = a;
	print_array1(a,5);		// 实参数组名, 形参数组名
	printf("\n");
	print_array1(p,5);		// 实参是指针, 形参数组名
	printf("\n");
	print_arrya2(a,5);		// 实参数组名, 形参指针
	printf("\n");
	print_arrya2(p,5);		// 实参数组名, 形参指针
	printf("\n");

	return 0;
}

void print_array1(int array[], int size){
	int *p;
	for(p=array; p<array+size;)
		printf("%d", *p++);
}

void print_array2(int *ap, int size){
	int *p
		for(p=ap; p<ap+size;)
			printf("%d", *p++);
}
