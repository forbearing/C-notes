#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str = "100 hyb";
	int id;
	char name[10];
	sscanf(str, "%d %s", &id, name);
	
	char stu[20];
	sprintf(stu, "%d %s", id, name);
	fprintf(stdout, "%s\n", stu);

	return 0;
}
