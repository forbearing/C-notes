/*
 * Copyright (c) 我的有限公司
 * 文件名: while.c
 * 描述: while 循环的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	/* while */
	int sum = 0;
	int i = 1;

	while(i <= 100){
		sum = sum + i;
		i = i + 1;
	}
	printf("sum: %d\n",sum);

	/* do-while */
	sum = 0;
	i = 0;
	do{
		sum = sum + i;
		i = i + 1;
	} while (i <= 100);
	printf("sum: %d\n",sum);
	return 0;
}
