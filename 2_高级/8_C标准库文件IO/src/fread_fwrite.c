/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: fread_fwrite.c
 * 描述: 学生信息的输入输出
 * 作者: Hyb
 * 完成日期: 2018年1月29日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

void text_to_bin(char *argv[]);
void bin_to_text(char *argv[]);

typedef struct{
	int xh;
	char name[20];
	int age;
}Student;

int main(int argc, char *argv[])
{
	if(argc != 4){
		printf("Usage: %s source target1 target2\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//text_to_bin(argv[1], argv[2]);
	//bin_to_text(argv[2], argv[3]);
	text_to_bin(argv);
	bin_to_text(argv);

	return 0;
}

void text_to_bin(char *argv[])
{
	Student stu;
	FILE *spIn, *spOut;
	spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		fprintf(stderr, "open source file error\n");
		exit(EXIT_FAILURE);
	}
	spOut = fopen(argv[2], "wb");
	if(spOut == NULL){
		fprintf(stderr, "open starget file error\n");
		exit(EXIT_FAILURE);
	}
	while(fscanf(spIn, "%d %s %d", &stu.xh, stu.name, &stu.age) != EOF){
		fwrite(&stu, sizeof(stu), 1, spOut);
	}
	fclose(spIn);
	fclose(spOut);
}
void bin_to_text(char *argv[])
{
	Student stu;
	FILE *spIn, *spOut;
	spIn = fopen(argv[2], "rb");
	if(spIn == NULL){
		fprintf(stderr, "Open souce file error\n");
		exit(EXIT_FAILURE);
	}
	spOut = fopen(argv[3], "w");
	if(spOut == NULL){
		fprintf(stderr, "Open target file error\n");
		exit(EXIT_FAILURE);
	}

	while(fread(&stu, sizeof(stu), 1, spIn) != 0){
		fprintf(spOut, "%d %s %d\n", stu.xh, stu.name, stu.age);
	}
	fclose(spIn);
	fclose(spOut);
}
