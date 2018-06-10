/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: pointer_array.c
 * 描述: 指针数组的介绍
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>

void out_num(int *nums[], int n);

int main(void)
{
	int num[] = {1,2,3,4,5};
	int *nums[5] = {&num[0], &num[1], &num[2], &num[3], &num[4]};

	out_num(nums, 5);

	return 0;
}

void out_num(int *nums[], int n)
{
	int i;
	for(i=0; i<5; i++){
		printf("%d ",*(nums[i]));
	}
	printf("\n");
}
