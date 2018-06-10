/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: feof.c
 * 描述: 临时记录 feof 函数的使用
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h> 

typedef struct{
	int xh;
	char name[20];
	int age;
}Student;

int main(int argc, char *argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: %s source target\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *spIn = fopen(argv[1] ,"r");
	if(spIn == NULL){
		fprintf(stderr, "Open source file error\n");
		exit(EXIT_FAILURE);
	}
	FILE *spOut = fopen(argv[2], "w");
	if(spOut == NULL){
		fprintf(stderr, "Open target file error\n");
		exit(EXIT_FAILURE);
	}

	Student stu;
	size_t size = fread(&stu, sizeof(stu), 1, spIn);
	if(size == 0)	return;
	// feof 仅限于使用在二进制文件中, 判断是否读到文件尾部
	whle(!feof(spIn)){
		fprintf(spOut, "%d %s %d\n", stu.xh, stu.name, stu.age);
		fread(&stu, sizeof(stu), 1, spIn);
	}
	
	fclose(spIn);
	fclose(spOut);

	return 0;
}
