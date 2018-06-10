/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: student_score.c
 * 描述: 统计一组学生的平均成绩和查找某名学生的成绩
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当期版本: 1.0
 */

#include <stdio.h>

#define ROW 3
#define COL 4

void average(int *p, int n);				// 列指针
void search (int (*p)[4], int n);			// 数组指针, 行指针

int main(void)
{
	int score[ROW][COL];
	int i,j;
	for(i=0; i<ROW; i++){
		printf("please input %d stduent score: ", i+1);
		for(j=0; j<COL; j++){
			scanf("%d", &score[i][j]);
		}
	}

	/* 计算平均成绩 */
	average(*score, ROW*COL);

	int bh;
	printf("please input bh: ");
	scanf("%d", &bh);
	if(bh < 0 || bh > ROW){
		printf("input bh error");
		return 1;
	}
	/* 根据编号查找某名学生并输出各科成绩 */
	search(score, bh-1);

	return 0;
}

void average(int *p, int n)
{
	int *s;
	int sum = 0;
	int aver = 0;
	for(s=p; s<p+n; s++){
		sum += *s;
	}
	aver = sum / n;
	printf("average: %d\n", aver);
}

void search (int (*p)[4], int n)
{
	//printf("%d %d %d %d\n", \
			*(*(p+n)+0), *(*(p+n)+1), *(*(p+n)+2), *(*(p+n)+3));
	int *s = *(p+n);
	int i;
	for(i=0; i<COL; i++)
		printf("%d ",*(s+i));
	printf("\n");
}
