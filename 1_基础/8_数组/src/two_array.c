/*
 * Copyright (c) 我的有限公司
 * 文件名: two_array.c
 * 描述: 二维数组的定义,初始化和遍历
 * 作者: hyb
 * 完成日期: 2017年12月26日
 * 当前版本: 1.0
 */

#include <stdio.h>

 void out_array(int array[][4], int row, int col);

int main(void)
{
	int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int b[3][4] = {
		{1,2,3,4},
		{5,6,7},
		{9,10,11,12}
	};
	int c[][4] = {
		{1},
		{2},
		{3}
	};

	int d [][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

	printf("array a:\n");
	out_array(a, 3, 4);
	printf("array b:\n");
	out_array(b, 3, 4);
	printf("array c:\n");
	out_array(c, 3, 4);
	printf("array d:\n");
	out_array(d, 4, 4);



	return 0;
}

void out_array(int array[][4], int row, int col)
{
	int i,j;
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}
