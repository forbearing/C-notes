/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: copy2.c
 * 描述: 利用 fgets 和 fputs 完成文件的拷贝
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
	if(argc != 3){
		printf("Usage: %s source target\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 打开目标文件和源文件 */
	FILE *spIn, *spOut;
	spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		printf("source file open error\n");
		exit(EXIT_FAILURE);
	}
	spOut = fopen(argv[2], "w");
	if(spOut == NULL){
		printf("target file open error\n");
		exit(EXIT_FAILURE);
	}


	/* 文件复制 */
	char content[100] = {'\0'};
	while(fgets(content, sizeof(content)-1, spIn) != NULL){
		fputs(content, spOut);
	}
	fclose(spIn);
	fclose(spOut);

	return 0;
}
