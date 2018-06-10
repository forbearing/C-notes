/*
 * Copyright (c) 我的有限公司
 * 文件名: calculator.c
 * 描述: 利用函数指针数组实现计算器功能
 * 作者: hyb
 * 完成日期: 2018年1月5日
 * 当前版本: 1.0
 */

#include <stdio.h>

int add(int i, int j)
{
	return i + j;
}

int sub(int i, int j)
{
	return i - j;
}

int mul(int i, int j)
{
	return i * j;
}

int div(int i, int j)
{
	return i / j;
}

void make_menu();

/* 定义函数指针数组 */
int (*fun_array[])(int, int) = {add, sub, mul, div};

int main(void)
{
	int i,j;
	int cmd;
	while(1){
		make_menu();
		scanf("%d", &cmd);
		if(cmd == 0) break;
		if(cmd >= 1 && cmd <= 4){
			printf("please input number1 and number2: ");
			scanf("%d%d", &i, &j);
			/* 通过函数指针数组去调用对应的函数 */
			// int result = fun_array[cmd-1](i, j);
			// int result = (*fun_array[cmd-1])(i, j);
			int (*p)(int,int) = fun_array[cmd-1];
			int result = p(i,j);
			printf("%d\n", result);
		}
	}
	return 0;
}

void make_menu(){
	printf("***************************\n");
	printf("Please chose a function:\n");
	printf("1:add two number\n");
	printf("2:sub two number\n");
	printf("3:mul two number\n");
	printf("4:div two number\n");
	printf("0:quit\n");
}
