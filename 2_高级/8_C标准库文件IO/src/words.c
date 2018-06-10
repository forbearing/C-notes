/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: words.c
 * 描述: 统计文件中的单词数量
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

#define WHITE_SPACE (c == ' ' || c ==  '\t' || c == '\n')

int main(int argc, char*argv[])
{
	if(argc != 2){
		printf("Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int c = 0;
	FILE *spIn = NULL;
	int words = 0;

	spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}

	while((c = fgetc(spIn)) != EOF)
		if(c = WHITE_SPACE)		words++;

	fclose(spIn);

	printf("total of word: %d\n", words);

	return 0;
}
