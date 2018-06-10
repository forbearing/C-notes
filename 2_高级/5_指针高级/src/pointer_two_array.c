/*
 * Copyright (c) 我的有限公司
 * 文件名: pointer_two_array.c
 * 描述: 二维数组地址的表示方式
 * 作者: Hyb
 * 完成日期: 2018年1月17日
 * 当期版本: 1.0
 */

#include <stdio.h>

int main(void)
{

	int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	/* a 和 &a[0] 是第一行地址, 
	 * *a 和 a[0] 是第一行第一列地址
	 * */
	printf("%p, %p, %p, %p\n", a, &a[0], *a, a[0]);
	/* a+1 和 &a[1] 是第二行地址
	 * *(a+1) a[1] 是第二行第一列地址
	 * */
	printf("%p, %p, %p, %p\n", a+1, &a[1], *(a+1), a[1]);
	printf("%p, %p, %p\n", *(a+1)+2, a[1]+2, &a[1][2]);

	return 0;
}
