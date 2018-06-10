/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: stumis.h
 * 描述: 案例:学生管理系统, 操作函数(增删改查函数)的声明
 * 作者: Hyb
 * 完成日期: 2018年1月12日
 * 当期版本: 1.0
 */

#include "student.h"
#define MAX_SIZE 100

/* 增加学生 */
extern void add_student(struct student stu);

/* 删除学生 */
extern void del_student(int xh);

/* 更新学生信息 */
extern void update_student(int xh, struct student newstu);

/* 查找指定学生 */
extern struct student find_student(int xh);

/* 查找所有学生 */
extern void findall();
