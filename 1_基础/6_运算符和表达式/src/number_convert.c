/*
 * Copyright (c) 我的有限公司
 * 文件名: number_convert.c
 * 描述: 将一个十进制数转换为二进制数
 * 作者: hyb
 * 完成日期: 2017年12月23日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int value;
	printf("pleae input one number: ");
	scanf("%d",&value);
	printf("binary of %d is:", value);

	int i = sizeof(value) * sizeof(int) - 1;		// 最多移动31位
	for(;i>=0;i--){
		int bit = (value >> i) & 1;
		printf("%d", bit);
	}
	printf("\n");

	return 0;
}
