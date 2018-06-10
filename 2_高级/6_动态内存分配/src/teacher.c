/*
 * Copyright (c) 2018 我的有限公司
 * 文件名:teacher.c
 * 描述: 教师操作的函数功能实现
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "teacher.h"

/* 定义一个指针 list 指向动态数组 */
static PElementType list;					// list 为结构体指针

/* list_size 指定动态数组的大小 */
static uint_t list_size;

/* counter 来统计 teacher 的实际数量 */
static uint_t counter;

/* 判断动态数组是否满 */
static uint_t is_full();

/* 判断动态数组是否为空 */
static uint_t is_empty();

/* 扩展动态数组 */
static void resize(uint_t increment);


/* 创建指定代大小的动态数组 */
void create(uint_t size)
{
	list = (PElementType)calloc(size, sizeof(ElementType));
	if(list == NULL){
		printf("create teacher error\n");
		exit(1);
	}
	list_size = size;
	counter = 0;
}
/* 销毁动态数组 */
void destroy()
{
	if(list == NULL) exit(1);
	free(list);
	list = NULL;
	list_size = 0;
	counter = 0;
}
/* 往动态数组中加入 teacher */
void add(PElementType p)
{
	if(list == NULL || p == NULL){
		printf("add teacher error\n");
		exit(1);
	}
	if(is_full()){
		resize(2);
	}
	list[counter++] = *p;
}
/* 在动态数组的指定位置插入 teacher */
void insert(uint_t index, PElementType p)
{
	if(list == NULL || p == NULL){
		printf("insert error\n");
		exit(1);
	}
	if(is_full()){
		resize(2);
	}
	int i;
	for(i=counter; i>index; i--){
		list[i] = list[i-1];
	}
	list[index] = *p;
	counter++;
}
/* 删除指定的 teacher */
void del(uint_t index)
{
	if(list == NULL){
		printf("del teacher error\n");
		exit(1);
	}
	if(is_empty()){
		printf("teacher is empty\n");
		exit(1);
	}
	int i;
	for(i = index; i<counter; i++){
		list[i] = list[i+1];
	}
	counter --;
}
/* 获得指定的 teacher */
PElementType get(uint_t index)
{
	if(list == NULL || index > counter){
		printf("get teacher error\n");
		exit(1);
	}
	if(index > counter){
		printf("get teacher error\n");
		exit(1);
	}
	return list + index;
}
/* 获得 teacher 的数量 */
uint_t size()
{
	return counter;
}
/* 遍历动态数组中的 teacher */
void iterate()
{
	if(list == NULL){
		printf("iterate error\n");
		exit(1);
	}
	int i;
	for(i=0; i<counter; i++){
		printf("%d %s %d %.2f\n", 
				(list+i)->id, (list+i)->name, (list+i)->age, (list+i)->salary);
	}
}

/* 判断动态数组是否满 */
static uint_t is_full()
{
	return counter >= list_size;
}
/* 判断动态数组是否为空 */
static uint_t is_empty()
{
	return counter == 0;
}
/* 扩展动态数组 */
static void resize(uint_t increment)
{
	list =(PElementType)realloc(list,(increment+list_size)*sizeof(ElementType));
	if(list == NULL){
		printf("resize capacity error\n");
		exit(1);
	}
	list_size += increment;
}
