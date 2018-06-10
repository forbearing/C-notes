/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: sscanf_sprintf.c
 * 描述: sscanf  和 sprintf 函数的使用
 * 作者: Hyb
 * 完成日期: 2018年1月29日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str = "hello iotek 2010";
	char str1[10] = {'\0'};
	char str2[10] = {'\0'};
	int year = 0;
	char array[50] = {'\0'};

	sscanf(str, "%s %s %d", str1, str2, &year);
	sprintf(array, "%s %s %d", str1, str2, year);
	printf("array: %s\n", array);
	
	/* 数字转化成字符串 */
	char nums[20] = {'\0'};
	int number = 123456;
	sprintf(nums, "%d", number);
	printf("%s\n", nums);

	return 0;
}
