/*
 * Copyright (c) 2013 上海海同信息科技有限公司
 * 文件名: sum.c
 * 描述: 利用 gdb 命令调试该程序
 * 完成日期: 2013年6月5日
 * 当前版本:1.0
 */

#include <stdio.h>

int my_sum(int size)
{
	int sum = 0;
	int i;
	for(i=1;i<=size;i++){
		sum = sum + i;
	}
	return sum;

}

int main(void)
{
	printf("please input size: ");
	int size = 0;
	scanf("%d",&size);
	int sum = my_sum(size);
	printf("sum: %d\n",sum);

	return 0;
}
