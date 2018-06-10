/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: malloc.c
 * 描述: malloc 函数的介绍
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <malloc.h>

void out(int *p, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", *(p+i));
	printf("\n-----------------\n");
}

int main(void)
{
	printf("please input one number: ");
	int n;
	scanf("%d", &n);
	/* 想系统申请一个大小为4个字节的内存块 */
	int *p = (int*)malloc(n * sizeof(int));
	if(p != NULL){
		out(p,n);
		int i;
		for(i=0; i<n; i++)
			*(p+i) = i*i;
		out(p,n);
		/* 释放资源 */
		free(p);
	}else{
		printf("malloc error\n");
	}

	return 0;
}
