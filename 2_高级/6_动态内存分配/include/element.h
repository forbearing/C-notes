/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: element.h
 * 描述: 射门结构体 teacher, 定义类型别名 ElementType 和 PElementType
 * 作者: Hyb
 * 完成日期: 2018年1月22日
 * 当前版本: 1.0
 */

struct teacher
{
	int id;
	int age;
	char *name;
	float salary;
};

typedef struct teacher ElementType;
typedef struct teacher* PElementType;
