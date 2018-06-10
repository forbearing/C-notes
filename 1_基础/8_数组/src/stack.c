/*
 * Copyright (c) 我的有限公司
 * 文件名: stack.c
 * 描述: 栈操作的函数功能实现
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#include "stack.h"

int stack[MAX_SIZE];
int position;					// 控制栈顶位置

/* 判断栈是否满 */
int is_full()
{
	return position >= MAX_SIZE;
}

/* 判断栈是否为空 */
int is_empty()
{
	return position == 0;
}

/* 入栈 */
void push(int element)
{
	if(is_full())
		return;
	stack[position++] = element;
	//position++;
}

/* 出栈 */
int popup()
{
	if(is_empty())
		return 0;
	//position--;
	int element = stack[--position];
	return element;
}

/* 获得栈顶元素 */
int top()
{
	if(is_empty())
		return 0;
	int element = stack[position-1];;
	return element;
}
