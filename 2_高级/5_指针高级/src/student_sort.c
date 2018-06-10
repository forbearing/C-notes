/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: student_sort.c
 * 描述: 从键盘输入若干个学生姓名并进行排序
 * 作者: hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>
#include <string.h>

void out_student(char (*p)[20], int n);
void sort_student(char (*p)[20], int n);		// 选择排序

int main(void)
{
	char student[3][20];
	int i;
	for(i=0; i<3; i++){
		//scanf("%s", student[i]);
		scanf("%s", *(student+i));
	}

	out_student(student, 3);
	sort_student(student, 3);
	out_student(student, 3);

	return 0;
}

void out_student(char (*p)[20], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%s ",*(p+i));
	printf("\n");
}

void sort_student(char (*p)[20], int n)			// 选择排序算法实现
{
	int i,j;
	for(i=0; i<n-1; i++){
		int pos = i;
		for(j=0; j<n; j++){
			if(strcmp(*(p+j), *(p+pos)) < 0)
				pos = j;
		}
		if(pos != i){
			char str[20] = {'\0'};
			strcpy(str, *(p+pos));
			strcpy(*(p+pos), *(p+i));
			strcpy(*(p+i), str);
		}
	}
}
