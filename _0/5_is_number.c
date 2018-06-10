/*
 * 文件名: is_number.c
 * 描述: 从终端读取并判断是否为数字
 * 完成日期: 2018年2月5日19:40
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char str[50];
	printf("please input string: \n");
	scanf("%s", str);

	int len = strlen(str);
	int i;
	for(i=0; i<len; i++){
		if(str[i] > '9' || str[i] < '0'){
			printf("not number\n");
			exit(1);
		}
			
	}
	printf("is number\n");

	return 0;
}
