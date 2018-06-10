/*
 * Copyright (c) 我的有限公司
 * 文件名: king.c
 * 描述: 打印一个金字塔
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int i, j, k, line;
	printf("please input line: ");
	scanf("%d", &line);
	if(line <= 0){
		printf("you input line is error\n");
	}
	
	i = 0;
	while(i < line){
		j = line;
		while(j > i){
			printf(" ");
			j--;
		}
		k = 0;
		while(k < 2*i+1){
			printf("*");
			k++;
		}

		printf("\n");
		i++;
	}

	return 0;
}
