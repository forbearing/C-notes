/*
 * Copyright (c) 我的有限公司
 * 文件名: stack.h
 * 描述: 声明对栈进行操作的函数原型
 * 作者: hyb
 * 完成日期: 2017年12月27日
 * 当前版本: 1.0
 */

#define MAX_SIZE 30

/* 判断栈是否满 */
int is_full();

/* 判断栈是否为空 */
int is_empty();

/* 入栈 */
void push(int element);

/* 出栈 */
int popup();

/* 获得栈顶元素 */
int top();
