/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: timer.c
 * 描述: 定时器功能实现
 * 作者: Hyb
 * 完成日期: 2018年1月8日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Usage:%s <number>\n", argv[0]);
		exit(1);
	}
	int duration = atoi(argv[1]);
	if(duration <= 0){
		printf("duration error\n");
		exit(1);
	}

	time_t start, current;
	time(&start);						// 设置启动时间
	printf("start time: %s\n", ctime(&start));
	do{
		time(&current);					// 设置当前时间
	}while((current-start) != duration);
	printf("current time: %s\n", ctime(&current));

	return 0;
}
