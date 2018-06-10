/*
 * Copyright (c) 我的有限公司
 * 文件名: bubble.c
 * 描述: 冒泡排序算法
 * 作者: hyb
 * 完成日期: 2017年12月25日
 * 当前版本: 1.0
 */

#include <stdio.h>

void out(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[5];
	printf("please input sort number: ");
	int k;
	for(k=0; k<5; k++)
		scanf("%d", &a[k]);

	int n = sizeof(a)/sizeof(int);
	int i, j;
	for(i=0; i<n-1; i++){
		for(j=n-1; j>i; j--){
			if(a[j] < a[j-1]){
				int temp;
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}

	out(a, n);

	return 0;
}
