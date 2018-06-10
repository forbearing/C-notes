/*
 * Copyright (c) 我的有限公司
 * 文件名; callback_test.c
 * 描述: 回调函数
 * 作者: Hyb
 * 完成日期: 2018年1月4日
 * 当前版本: 1.0
 */

#include "callback.h"
#include <stdio.h>

char get_grade(int score)
{
	if(score >= 90)
		return 'A';
	else if(score >= 80)
		return 'B';
	else if(score >= 70)
		return 'C';
	else if(score >= 60)
		return 'D';
	else
		return 'N';
}

int main(void)
{
	int score;
	printf("please input your score: ");
	scanf("%d", &score);

	printf("result: %c\n",process(score,get_grade));

	return 0;
}
