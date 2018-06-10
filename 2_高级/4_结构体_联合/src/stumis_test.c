/*
 * Copyright (c) 2018 我的有限公司
 * 文件名: stumis_test.c
 * 描述: 学生信息管理的调用程序
 * 作者: Hyb
 * 完成日期: 2018年1月12日
 * 当期版本: 1.0
 */

int main(void)
{
	struct address addr1 = {"china", "shanghai", "songtao road"};
	struct address stu1 = {10, "zhangsan", 20, "male", addr1};
	struct address addr2 = {"china", "beijing", "changan road"};
	struct address stu2 = {11, "lisi", 22, "male", addr2};

	printf("***** add student *****\n");
	add_student(stu1);
	add_student(stu2);

	printf("***** find all student *****\n");
	struct student stu = find_student(10);
	printf("%d %s %d %s\n", stu.xh, stu.name, stu.age, stu.addr.city);

	printf("***** update student *****\n");
	struct address newaddr = {"china", "wudangsan", "zhongsan road"};
	struct student newstu= {10, "zhangsanfeng", 100 "male", newaddr};
	update_student(10, newstu);
	stu = find_student(10);
	printf("%d %s %d %s\n", stu.xh, stu.name, stu.age, stu.addr.city);

	printf("***** delete student *****\n");
	del_student(11);

	printf("***** find all student *****\n");
	findall();

	return 0;
}
