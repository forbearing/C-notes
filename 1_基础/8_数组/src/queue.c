/*
 * Copyright (c) hyb有限公司
 * 文件名: queue.c
 * 描述: 队列操作的函数功能实现
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#include "queue.h"

int queue[MAX_SIZE];
unsigned int position;		// 非负整型
void remove(unsigned int index);

/* 判断队列是否满 */
int is_full()
{
	return position >= MAX_SIZE;
}

/* 判断队列是否为空 */
int is_empty()
{
	return position == 0;
}

/* 入列 */
void enqueue(int element)
{
	if(is_full())
		return;
	queue[position++] = element;
}

/* 出列 */
int dequeue()
{
	if(is_empty())
		return 0;
	int element = queue[0];
	/* 删除队列头部的元素 */
	remove(0);
	position--;
	return element;
	
/*
 *	int i;
	for(i=0; i<position; i++){
		queue[i] = queue[i+1];
	}
	position--;
*/
}

void remove(unsigned int index)
{
	int i;
	for(i=index; i<position-1; i++)
		queue[i] = queue[i+1];
	queue[i] = 0;
}
