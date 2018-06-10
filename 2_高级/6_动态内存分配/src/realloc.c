/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: realloc.c
 * 描述: realloc 的介绍和使用
 * 作者: Hyb
 * 完成日期: 2018年1月22日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

void out(int *p, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", *(p+i));
	printf("\n");
}

int main(void)
{
	int *p = (int*)calloc(5, sizeof(int));
	if(p == NULL) exit(1);
	*p = 1;
	*(p+1) = 2;
	p[2] = 3;
	p[3] = 4;
	*(p+4) = 5;
	out(p,5);
	printf("-------------------------------\n");

	/* 扩展内存块大小 */
	p = (int*)realloc(p, 7*sizeof(int));
	if(p == NULL) exit(1);
	*(p+5) = 6;
	*(p+6) = 7;
	out(p,7);
	free(p);
	/* p为野指针 */
	p = NULL;
	/*
	printf("----------- after free -----------\n");
	*(p+6) = 77;
	out(p, 7);
	*/

	return 0;
}
