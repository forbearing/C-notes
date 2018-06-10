/*
 * Copyright (c) 我的有限公司
 * 文件名: switch.c
 * 描述: switch 语句的介绍和使用
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
/*
	enum Grade{EXCELLENCE, GOOD, PASS, FAILURE};
	enum Grade grade = GOOD;
	switch(grade){
		case EXCELLENCE:
			printf("Excellence!\n");
			break;
		case GOOD:
			printf("Good!\n");
			break;
		case PASS:
			printf("Pass!\n");
			break;
		case FAILURE:
			printf("Failure!\n");
			break;
		default:
			printf("Unknow!\n");
			break;
	}
*/

	printf("Please input month:\n");
	int month;
	scanf("%d",&month);
	switch(month){
		case 1: case 3: case 5: case 7: case 8:  case 10: case 12:
			printf("31 days\n");
			break;
		case 2:
			printf("28 day\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30 days\n");
			break;
		default:
			printf("error\n");
			break;
	}

	return 0;
}
