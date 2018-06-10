/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: error.c
 * 描述: 野指针
 * 作者: hyb
 * 完成日期: 2018年1月23日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

void malloc_test(int size)
{
	int *p = NULL, *s = NULL;
	p = (int *)malloc(size * sizeof(int));
	if(p == NULL)	exit(1);
	
	printf("befor free p: %p\n", p);
	for(s=p; s<p+size; s++)
		printf(" %d ",*s);
	printf("\n");

	printf("after free p: %p\n", p);
	free(p);
	if(p != NULL){				// p 是一个野指针,不能使用它
		for(s = p; s<p+size; s++)
			printf(" %d ", *s);
		printf("\n");
	}

	p = NULL;					// 将野指针设置为 NULL 指针
}

int main(void)
{
	int size;
	printf("Please input a number: ");
	scanf("%d", &size);
	malloc_test(size);

	return 0;
}
