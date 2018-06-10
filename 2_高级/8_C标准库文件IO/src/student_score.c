/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: student_score.c
 * 描述: 统计学生的成绩并计算等级输出到另外一个文件中
 * 作者: Hyb
 * 完成日期: 2018年1月28日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <stdlib.h>

/* 根据平均成绩返回等级 */
char get_grade(float average);

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Usage: %s source target\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1:定义重要相关变量 */
	int xh;
	char name[20] = {'\0'};
	int score1, score2, score3;
	char grade;
	float average;

	/* 2:打开两个文件 */
	FILE *spIn;
	spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		printf("open souce file error\n");
		exit(EXIT_FAILURE);
	}
	FILE *spOut;
	spOut = fopen(argv[2], "w");
	if(spOut == NULL){
		printf("target souce file error\n");
		exit(EXIT_FAILURE);
	}

	/* 3:统计并将结果写入目标文件 */
	while(fscanf(spIn,"%d %s %d %d %d", 
				&xh, name, &score1, &score2, &score3) != EOF){
		average = (score1 + score2 + score3) / 3;
		grade = get_grade(average);
		fprintf(spOut, "%d %s %.2f %c\n", xh, name, average, grade);
	}

	/* 4:关闭文件 */
	fclose(spIn);
	fclose(spOut);

	return 0;
}

char get_grade(float average)
{
	if(average >= 90)
		return 'A';
	else if(average >= 80)
		return 'B';
	else if(average >= 70)
		return 'C';
	else
		return 'D';
}
