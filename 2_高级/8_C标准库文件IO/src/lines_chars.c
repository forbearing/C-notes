/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: lines_chars.c
 * 描述: 统计文件爱呢的行数和大小
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	if(argc != 2){
		printf("Usage: %s filepath\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	int lines = 0;
	int chars = 0;

	/* 1:打开目标文件 */
	FILE *spIn;
	spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}

	/* 2:统计文件 */
	int ch;
	while((ch = fgetc(spIn)) != EOF){
		chars++;
		if(ch == '\n')	lines++;
	}

	/* 3:关闭文件 */
	fclose(spIn);

	/* 4:打印结果 */
	printf("lines total: %d\n", lines);
	printf("file size: %d\n", chars);

	return 0;
}
