/*
 * Copyright (c) 2013 我的有限公司
 * 文件名: mult99.c
 * 描述: 打印一个九九乘法表
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int temp;
	// 第一种形式
	int i,j;
	for(i=1;i<10;i++){
		for(j=1;j<=i;j++){
			temp = i * j;
			printf("%d*%d",j,i);
			if(temp < 10)
				printf("= %d  ",temp);
			else
				printf("=%d  ",temp);
		}
		printf("\n");
	}

	return 0;
}
