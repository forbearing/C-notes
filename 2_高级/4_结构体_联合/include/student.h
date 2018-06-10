/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: student.h
 * 描述: 学生管理系统,声明学生结构体类型
 * 作者: Hyb
 * 完成日期: 2018年1月12日
 * 当前版本: 1.0
 */

struct address
{
	char country[20];
	char city[20];
	char street[30];
};

struct student
{
	int xh;
	char name[30];
	char gender[20];
	int age;
	struct address addr;
}
