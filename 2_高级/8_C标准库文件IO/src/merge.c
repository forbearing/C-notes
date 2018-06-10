/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: merge.c
 * 描述: 将两个文件合并,并且输出到另外一个文件中(按字母顺序排列)
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

void sort(char content[], int n);

int main(int argc, char*argv[])
{
	if(argc != 4){
		printf("Usage: %s file_A file_B file_C\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1:打开第一个文件 */
	FILE *fp1;
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL){
		printf("file_A open error\n");
		exit(EXIT_FAILURE);
	}

	/* 2:打开第二个文件 */
	FILE *fp2;
	fp2 = fopen(argv[2], "r");
	if(fp2 == NULL){
		printf("file_B open error\n");
		exit(EXIT_FAILURE);
	}

	/* 3:打开第三个文件 */
	FILE *fp3;
	fp3 = fopen(argv[3], "w");
	if(fp3 == NULL){
		printf("file_C open error\n");
		exit(EXIT_FAILURE);
	}

	/* 4:写入字符数组 */
	char content[100] = {'\0'};
	int i = 0;
	int ch;
	while((ch = fgetc(fp1)) != EOF){
		putchar(ch);
		if(ch == '\n' || ch == ' ' || ch == '\t')
			continue;
		content[i++] = ch;
	}
	fclose(fp1);
	while((ch = fgetc(fp2)) != EOF){
		fputc(ch, stdout);
		if(ch == '\n' || ch == ' ' || ch == '\t')
			continue;
		content[i++] = ch;			// i为实际元素个数,而不是元素下标
	}
	fclose(fp2);
	
	/* 5:对字符数组进行排序 */
	int n = i;
	sort(content, n);

	/* 6:将排序好的字符数组写入第三个文件 */
	for(i=0; i<n; i++){
		putchar(content[i]);
		fputc(content[i], fp3);
	}
	putchar('\n');
	fputc('\n', fp3);
	fclose(fp3);

	return 0;
}

void sort(char content[], int n)
{

	int i,j;
	for(i=0; i<n-1; i++){
		int pos = i;
		for(j=i+1; j<n; j++){
			if(content[j] < content[pos])
				pos = j;
		}
		if(pos != i){
			char ch;
			ch = content[pos];
			content[pos] = content[i];
			content[i] = ch;
	}
	}
}
