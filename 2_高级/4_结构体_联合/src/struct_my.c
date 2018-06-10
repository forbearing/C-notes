#include <stdio.h>
#include <string.h>

struct address{
	char *country;
	char *city;
	char *street;
};
struct student{
	int xh;
	char *name;
	char *sex;
	int age;
	struct address *addr;
};

int main(void)
{
	struct address ad = {"china", "Shanghai", "zhongsan road"};
	struct student stu = {1, "hyb", "male", 21, &ad};
	struct student *stu_p = &stu;
	printf("name: %s\n", stu_p->name);
	printf("street: %s\n", stu_p->addr->street);

	return 0;
}
