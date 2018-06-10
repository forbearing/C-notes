/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: copy.c
 * 描述: 利用 fgetc 和 fputc 完成文件的复制
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *spIn, *spOut;
	/* 打开输入流 */
	spIn = fopen("/etc/passwd", "r");
	if(spIn == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}
	
	/* 打开输出流 */
	spOut = fopen("./passwd", "w");
	if(spOut == NULL){
		printf("open file error\n");
		exit(EXIT_FAILURE);
	}

	/* 文件拷贝 */
	int ch;
	while((ch = fgetc(spIn)) != EOF){
		fputc(ch, spOut);
	}

	/* 关闭流 */
	if(fclose(spIn) != 0){
		printf("close file error\n");
		exit(EXIT_FAILURE);
	}
	if(fclose(spOut) != 0){
		printf("close file error\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
