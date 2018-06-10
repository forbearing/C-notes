/*
 * Copyright (c) 我的有限公司
 * 文件名: queue.h
 * 描述: 声明对队列进行操作的函数原型
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#define MAX_SIZE 30

/* 判断队列是否满 */
int is_full();

/* 判断队列是否为空 */
int is_empty();

/* 入列 */
void enqueue(int element);

/* 出列 */
int dequeue();
