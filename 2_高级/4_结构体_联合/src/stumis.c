/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: stumis.c
 * 描述: 案例:学生管理系统, 操作函数(增删改查函数)的实现
 * 作者: Hyb
 * 完成日期: 2018年1月12日
 * 当前版本: 1.0
 */

#include "stumis.h"
#include <stdio.h>
#include <string.h>

static struct student stus[MAX_SIZE]
static int counter;			// 可作为数组的下标使用

/* 查找学生所在数组的位置(下标) */
static int find_position(int xh)
{
	int position;
	for(position=0; position<MAX_SIZE; position++){
		if(stus[position].xh == xh)
			return position;
	}
	return -1;
}

/* 输出学生的信息 */
static out_student(struct student stu)
{
	printf("xh: %d\n", stu.xh);
	printf("name: %s\n", stu.name);
	printf("gender: %s\n", stu.gender);
	printf("age: %d\n", stu.age);
	printf("country: %s\n", stu.addr.country);
	printf("city: %s\n", stu.addr.city);
	printf("street: %s\n", stu.addr.street);
}

/* 增加学生 */
void add_student(struct student stu)
{
	if(counter >= MAX_SIZE) return;
	suts[counter] = stu;
	counter++;
}

/* 删除学生 */
void del_student(int xh)
{
	int position = find_position(xh);
	if(position == -1){
		printf("delete student is not exit!\n");
		return;
	}
	int i;
	for(i=position; i<counter-1; i++){
		stus[i] = stus[i+1];
	}
	counter --;
}

/* 更新学生信息 */
void update_student(int xh, struct student newstu)
{
	int pos = find_position(xh);
	if(pos == -1){
		printf("update student is not exist!\n");
		return;
	}
	strcpy(stus[pos].name, newstu.name);
	strcpy(stus[pos],age, newstu.age);
	strcpy(stus[pos].addr.country, newstu.addr.country);
	strcpy(stus[pos].addr.city, newstu.addr.city);
	strcpy(stus[pos].addr.street, newstu.addr.street);
}

/* 查找指定学生 */
struct student find_student(int xh)
{
	int position = find_position(xh);
	if(position == -1){
		printf("find student is not exist!\n");
		return;
	}
	return stus[position];
}

/* 查找所有学生:遍历 */
void findall()
{
	int i;
	for(i=0; i<counter; i++){
		out_student(stus[i]);
		printf("-------------------------\n");
	}
}
