/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: fseek.c
 * 描述: fseek 函数的使用
 * 作者: Hyb
 * 完成日期: 2018年1月29日
 * 当前版本: .10
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int xh;
	char name[20];
	int age;
}Student;

int main(int argc, char*argv[])
{
	if(argc != 3){
		printf("Usage: %s source target\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	Student stu;
	FILE *spIn;
	spIn = fopen(argv[1], "rb");
	if(spIn == NULL){
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE *spOut;
	spOut = fopen(argv[2], "w");
	if(spOut == NULL){
		perror("argv[2]");
		exit(EXIT_FAILURE);
	}

	int i;
	for(i=0; i<3; i++){
		fseek(spIn, i*sizeof(stu), SEEK_SET);
		fread(&stu, sizeof(stu), 1, spIn);
		fprintf(spOut, "%d %s %d\n", stu.xh, stu.name, stu.age);
	}

	fclose(spIn);
	fclose(spOut);

	return 0;
}
