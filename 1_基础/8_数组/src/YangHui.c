/*
 * Copyright (c) 我的有限公司
 * 文件名: YangHui.c
 * 描述: 打印一个杨辉三角形
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int a[20][20];
	int i,j;
	for(i=0; i<20; i++)			// 初始化数组
		for(j=0; j<20; j++)
			a[i][j] = 0;
	
	int row;
	printf("please input raw: ");
	scanf("%d", &row);

	for(i=0; i<row; i++){
		for(j=0; j<=i; j++){
			/* 判断第一列或者对角线 */
			if(j == 0 || i == j)
				a[i][j] = 1;
			/* 除了上述两条边以外的数 */
			else
				a[i][j] = a[i-1][j] + a[i-1][j-1];
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
