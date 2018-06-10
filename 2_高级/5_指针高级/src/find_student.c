/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: find_student.c
 * 描述: 根据姓名查找学生是否存在
 * 作者: Hyb
 * 完成日期: 2018年1月20日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>

int find(char **pp, char *name);

int main(void)
{
	char *students[] = {"zhangsan", "lisi", "wangwu", NULL};
	char name[20] = {'\0'};
	printf("please input your name: ");
	scanf("%s", name);
	
	int result = find (students, name);
	if(result){
		printf("find student\n");
	}else{
		printf("not find\n");
	}

	return 0;
}

int find(char **pp, char *name)
{
	if(pp == NULL || name == NULL)
		return 0;
	while(*pp != NULL){
		if(strcmp(*pp, name) == 0){
			return 1;
		}
		pp++;
	}
	return 0;
}
