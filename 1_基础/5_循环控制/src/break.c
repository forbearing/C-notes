/*
 * Copyright (c) 我的有限公司
 * 文件名: break.c
 * 描述: break 和 continue 的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int sum = 0;
	int i = 1;
	while(i <= 100){
		sum += i;
		i++;
		if(i == 50)
			//break;
			continue;
		printf("i: %d\n",i);
	}
	printf("sum: %d\n",sum);

	return 0;
}
