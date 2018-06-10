#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int xh;
	char name[20];
	int age;
}Student;

int main(int argc, char*argv[])
{
	if(argc != 3){
		fprintf(stderr, "Usage: %s source_file target_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *spIn = fopen(argv[1], "r");
	if(spIn == NULL){
		fprintf(stderr, "Open souce file error\n");
		exit(EXIT_FAILURE);
	}
	FILE *spOut = fopen(argv[2], "w");
	if(spOut == NULL){
		fprintf(stderr, "Open target file error\n");
		exit(EXIT_FAILURE);
	}

/*	int ch;
	while((ch = fgetc(spIn)) != EOF)
		fputc(ch, spOut);
*/
/*	char str[20] = {'\0'};
	while(fgets(str, sizeof(str)-1, spIn) != NULL)
		fputs(str, spOut);
*/
/*	Student stu;
	while(fscanf(spIn, "%d %s %d", &stu.xh, stu.name, &stu.age) != EOF){
		fprintf(spOut, "%d %s %d", stu.xh, stu.name, stu.age);
	}
*/
	char str[20] = {'\0'};
	while(fread(str, sizeof(str)-1, 1, spIn) != 0)
		fwrite(str, sizeof(str)-1, 1, spOut);

	fclose(spIn);
	fclose(spOut);

	return 0;
}
