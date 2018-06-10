/*
 * Copyright (c) 我的有限公司
 * 文件名: count_age.c
 * 描述: 从键盘输入一组年龄并统计各阶段年龄的人数
 * 作者: hyb
 * 完成日期: 2017年12月21日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int persons[10];
	printf("please input ages: ");
	int i;
	for(i=0; i<10; i++){
		scanf("%d", &persons[i]);
	}

	int ages[11];
	for(i=0; i<11; i++)
		ages[i] = 0;
	
	for(i=0; i<10; i++){
		int k = persons[i]/10;
		if(k >= 10)
			ages[10]++;
		else
			ages[k]++;
	}

	for(i=0; i<11; i++)
		printf("ages[%d]: %d\n",i, ages[i]);

	return 0;
}
