/*
 * Copyright (c) 我的有限公司
 * 文件名: array_init.c
 * 描述: 一维数组的定义和初始化
 * 作者: hyb
 * 完成日期: 2017年12月21日
 * 当前版本: 1.0
 */


#include <stdio.h>

void out_array(int array[], int size);

int main(void)
{
	int a1[10] = {1,2,3,4,5,6,7,8,9,10};
	/* 初始化1: 部分初始化 */
	int a2[10] = {1};
	/* 初始化2: 初始化为0 */
	int a3[10] = {0};
	/* 初始化3: 不指定数组长度 */
	int a4[] = {1,2,3,4,5,6,7,8,9,10};

	int a5[5];
	int a6[5];
	int a7[5];
	//out_array(a5, sizeof(a5)/sizeof(int));
	
	int i;
	/* 赋值1: */
	for(i=0; i<5; i++){
		a5[i] = i + 1;
	}

	/* 赋值2: 将数组 a5 复制给数组 a6 */
	for(i=0; i<5; i++){
		a6[i] = a5[i];
	}

	/* 赋值3: */
	printf("please input array element: ");
	for(i=0; i<5; i++){
		scanf("%d",&a7[i]);
	}

	printf("array a1:  ");
	out_array(a1, sizeof(a1)/sizeof(int));
	printf("array a2:  ");
	out_array(a2, sizeof(a2)/sizeof(int));
	printf("array a3:  ");
	out_array(a3, sizeof(a3)/sizeof(int));
	printf("array a4:  ");
	out_array(a4, sizeof(a4)/sizeof(int));
	printf("array a5:  ");
	out_array(a5, sizeof(a5)/sizeof(int));
	printf("array a6:  ");
	out_array(a6, sizeof(a6)/sizeof(int));
	printf("array a7:  ");
	out_array(a7, sizeof(a7)/sizeof(int));

	return 0;
}

void out_array(int array[], int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
