/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: calloc.c
 * 描述: calloc 的介绍和使用
 * 作者: hyb
 * 完成日期: 2018年1月20日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("please input one number: ");
	int n;
	scanf("%d", &n);
	int *p = (int *)calloc(n, sizeof(int));
	if(p != NULL){
		int i;
		for(i=0; i<n; i++)
			printf("%d ", *(p+i));
		printf("\n");
		free(p);
	}else{
		printf("calloc error\n");
	}

	return 0;
}
