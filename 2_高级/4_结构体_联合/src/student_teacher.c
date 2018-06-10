/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: student_teacher.c
 * 描述: 学生和教师信息的录入和输出
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */

#include <stdio.h>

struct
{
	char name[10];
	char sex;
	char job;
	int num;
	union{
		int class;
		char position[10];
	}category;
}person[2];

int main(void)
{
	int i;
	for(i=0; i<2; i++){
		printf("Please enter NUM NAME SEX JOB\n");
		scanf("%d %s %c %c", 
				&person[i].num, person[i].name, &person[i].sex, &person[i].job);
		if(person[i].job == 's'){
			printf("Please enter CLASS: ");
			scanf("%d", &person[i].category.class);
		}else if(person[i].job == 't'){
			printf("Please enter POSITION: ");
			scanf("%s", person[i].category.position);
		}else{
			printf("input error");
		}
	}

	printf("\n");
	printf("No.\tName\tsex\tjob\tclass/position\n");
	for(i=0; i<2; i++){
		if(person[i].job == 's'){
			printf("%-6d %-10s %-3c %-3c %-6d\n",person[i].num, person[i].name, 
					person[i].sex, person[i].job, person[i].category.class);
		}else{
			printf("%-6d %-10s %-3c %-3c %-6s\n",person[i].num, person[i].name,
					person[i].sex, person[i].job, person[i].category.position);
		}
	}

	return 0;
}
