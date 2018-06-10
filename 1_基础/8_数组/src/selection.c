/*
 * Copyright (c) 我的有限公司
 * 文件名: selection.c
 * 描述: 选择排序算法
 * 作者: hyb
 * 完成日期: 2017年12月26日
 * 当前版本: 1.0
 */

#include <stdio.h>

void out(int a[], int n)
{
	int i;
	for(i=0; i<n; i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[5];
	printf("please input sort number: ");
	int k;
	for(k=0; k<5; k++)
		scanf("%d",&a[k]);
	int n = sizeof(a)/sizeof(int);
	int i,j;

	for(i=0; i<n-1; i++){	// 循环 n-1 轮
		int pos = i;
		for(j=i+1; j<n; j++){
			if(a[j] < a[pos])
				pos = j;
		}
		if(pos != i){
			int temp;
			temp = a[pos];
			a[pos] = a[i];
			a[i] = temp;
		}
	}
	out(a,n);

	return 0;
}
