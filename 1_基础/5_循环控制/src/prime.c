/*
 * Copyright (c) 我的有限公司
 * 文件名: prime.c
 * 描述: 判断 101-200 之间有多少个素数,并输出所有素数
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int m, i, k, h = 0, leap = 1;
	for(m = 101; m <= 200; m++){
		k = sqrt(m+1);
		for(i = 2; i <= k; i++){
			if(m % i == 0){
				leap = 0;	// m 为合数
				break;
			}
		}
		if(leap){			// m 为素数
			printf("%-4d",m);
			h++;
			if(h % 5 == 0)
				printf("\n");
		}
		leap = 1;
	}
	printf("\nThe total is %d\n",h);

	return 0;
}
