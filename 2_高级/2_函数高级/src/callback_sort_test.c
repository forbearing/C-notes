/*
 * Copyright (c) 我的有限公司
 * 文件名: callback_sort_test.c
 * 描述: 调用程序
 * 作者: Hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "callback_sort.h"

/* 冒泡排序算法 */
void bulle_sort(int *p, int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>i; j--){
			if(*(p+j) < *(p+j-1)){
				int temp;
				temp = *(p+j);
				*(p+j) = *(p+j-1);
				*(p+j-1) = temp;
			}
		}
	}
}

/* 选择排序算法 */
void selection_sort(int *p, int n)
{
	int i,j;
	for(i=0; i<n-1; i++){
		int pos = i;
		for(j=i+1; j<n; j++){
			if(*(p+j) < *(p+pos)){
				pos = j;
			}
		}
		if(pos != i){
			int temp;
			temp = *(p+pos);
			*(p+pos) = *(p+i);
			*(p+i) = temp;
		}
	}
}

/* 输出数组中的元素 */
void out_data(int data[], int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

int main(void)
{
	int data1[] = {4, 2, 1, 6, 5};
	int n = sizeof(data1)/4;
	data_sort(data1, n, bulle_sort, out_data);
	data_sort(data1, n, selection_sort, out_data);

	int data2[] = {6, 7, 4, 1, 8};
	data_sort(data2, n, bulle_sort, out_data);
	data_sort(data2, n, selection_sort, out_data);

	return 0;
}
