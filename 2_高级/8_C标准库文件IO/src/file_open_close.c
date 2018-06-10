/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: file_open_close.c
 * 描述: 文件打开和关闭
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	fp = fopen("/etc/passwd", "r");
	if(fp == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}

	int pos = ftell(fp);
	printf("pos: %d\n", pos);

	if(fclose(fp) != 0){
		printf("close file error\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
