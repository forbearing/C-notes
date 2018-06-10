#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void out_student(struct student stu);

int main(int argc, char*argv[])
{
	/* 定义结构体变量并初始化 */
	struct address addr{"China", "shanghai", "songtao road"};
	struct student stu1 = {1, "zhangsan", "male", 20, addr};
	struct student stu2 = {2, "lisi", "male", 21, 
		{"China", "Beijing", "changan road"}};

	exit(EXIT_SUCCESS);
}

void out_student(struct student stu)
{
	printf("xh:%d\n",  stu.xh);
	printf("name:%s\n", stu.name);
	printf("gender:%s\n", stu.gender);
	printf("age:%d\n", stu.age);
}
