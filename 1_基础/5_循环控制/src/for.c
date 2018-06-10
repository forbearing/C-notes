/*
 * Copyright (c) 我的有限公司
 * 文件名: for.c
 * 描述: for 循环的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int sum = 0;
	for (int i=1; i<=100; i++){
		sum += i;
	}
	
	// for(;;);			死循环
	// for(;1;);		死循环
	
	printf("sum: %d\n",sum);

	return 0;
}
