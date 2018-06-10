结构体
	1:结构体变量的声明的大括号后忘了";"
	2:结构体变量成员名的注意点
		struct address{
			char *country;
			char *city;
			char *street;
		};
		struct student{
			int xh;
			char *name;
			char *sex
			int age;
			struct addrss *addr;
		}
		struct address ad = {"china", "shanghai", "zhongsan road"};
		struct student stu = {1, "hyb", "male", 21, &ad};
		struct student *stu_p = &stu;
		printf("street: %s\n", stu_p->addr->street);
		// 而不是
		//printf("street: %s\n", stu_p->ad-.street);
		// 实际上是 ad 赋值给 addr.




总结
