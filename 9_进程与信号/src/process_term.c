/*
 * 文件名: process_term.c
 * 描述: 进程终止, atexit 的介绍和使用
 * 完成日期: 2018年2月6日17:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void term_fun1(void){
	printf("first term function\n");
}
void term_fun2(void){
	printf("second term function\n");
}
void term_fun3(void){
	printf("thrid term function\n");
}

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s file [exit|_exit|return]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 向内核登记终止函数 */
	atexit(term_fun1);
	atexit(term_fun2);
	atexit(term_fun3);

	/* 向文件中写入内容 */
	FILE *fp = fopen(argv[1], "w");
	if(fp == NULL){
		perror("fopen error");
		exit(EXIT_FAILURE);
	}
	fprintf(fp, "hello linux\n");

	/* 判断使用的进程终止方式 */
	if(!strcmp(argv[2], "exit")){
		exit(0);
	}else if(!strcmp(argv[2], "_exit")){
		_exit(0);
	}else if(!strcmp(argv[2], "return")){
		return 0;
	}else{
		fprintf(stderr, "Usage: %s file [exit|_exit|return]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fclose(fp);

}
