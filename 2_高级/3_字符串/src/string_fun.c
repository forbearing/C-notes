/*
 * Copyright (c) 2018年1月7日
 * 文件名: string_fun.c
 * 描述: 字符串函数的介绍和使用
 * 作者: hyb
 * 完成日期: 2018年1月7日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	/* gets puts, fgets fputs */
	char array[20] = {'\0'};
	//gets(array);				//不建议使用
	//puts(array);
	fgets(array, sizeof(array)-1, stdin);
	fputs(array, stdout);

	char *str1 = "hello world";
	printf("str1 length: %d\n", strlen(str1));
	printf("--------------------------------------\n");
	
	/* strcpy, strncpy */
	char str2[20] = {'\0'};
	strcpy(str2, str1);
	printf("after strcpy(...), str2: %s\n", str2);
	char str3[10] = {'\0'};
	strncpy(str3, str1, 7);
	printf("after strncpy(...), str3: %s\n", str3);
	printf("--------------------------------------\n");

	/* strcmp, strncmp */
	char *str4 = "hello";
	char *str5 = "hello";
	if(strcmp(str4, str5) == 0)
		printf("strcmp(...), str4 equals str5!\n");
	else
		printf("strcmp(...), str4 not equals str5!\n");
	str4 = "hello world";
	if(strncmp(str4, str5, 5) == 0)
		printf("strncmp(...), str4 equals str5!\n");
	else
		printf("strncmp(...), str4 not equals str5!\n");
	printf("--------------------------------------\n");

	/* strcat */
	//char *str6 = "Linux";			// segmentation fault
	char str6[20] = "Linux";
	strcat(str6, str5);
	printf("after strcat(..), str6: %s\n", str6);
	printf("--------------------------------------\n");

	/* strchr, strrchr */
	char *str7 = strchr(str6, 'l');
	printf("str7:%p, %c\n", str7, *str7);
	char *str8 = strrchr(str6, 'l');
	printf("str8:%p, %c\n", str8, *str8);
	if(strchr(str6, 'o') != NULL)
		printf("str6 contains o!\n");
	else
		printf("str6 not contains o !\n");
	printf("--------------------------------------\n");

	/* strstr */
	char *str9 = "hello";
	char *str10 = "my hello world";
	if(strstr(str10, str9) != NULL)
		printf("str10 contain str9\n");
	else
		printf("str10 not contain str9\n");
	printf("--------------------------------------\n");

	/* strtok */
	char str[] = "hello:iotek:hello:jack";
	int counter = 0;
	char *p = strtok(str,":");
	while(p != NULL){
		counter ++;
		printf("%s ", p);
		p = strtok(NULL, ":");
	}
	printf("\n");
	printf("counter:%d\n", counter);
	printf("--------------------------------------\n");

	char *src = "hello china";
	char dest[30];
	memset(dest, 0, sizeof(dest));
	memcpy(dest, src, sizeof(dest)-1);
	printf("dest: %s\n", dest);

	return 0;
}
