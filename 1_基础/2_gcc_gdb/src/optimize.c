/* 
 * Copyright (c) 2013 上海海同信息科技有限公司
 * 文件名: optimize.c
 * 描述: 通过 gcc 命令的选项(-O -O2 -O3)对循环程序进行优化
 * 作者: iotek
 * 完成日期: 2013年6月5日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	double counter;
	double result;
	double temp;
	for (counter=0; counter<4000.0*4000.0*4000.0/20.0+2030; 
									counter+=(5-3+2+1)/4){
		temp = counter/1239;
		result = temp;
	}
	
	printf("Result is %lf\n",result);
	return 0;
}
