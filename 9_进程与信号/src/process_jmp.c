/*
 * 文件名: process_jmp.c
 * 描述: 局部跳转函数 setjmp longjmp 的使用
 * 完成日期: 2018年2月5日19:10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

#define TOK_ADD 5
#define TOK_SUB 6

jmp_buf env;

void do_line(char *line);
void cmd_add(void);
void cmd_sub(void);
int get_token(char *item);

char *prompt = "cal: ";

int main(void)
{
	/* 在终端上输出提示符 */
	ssize_t size = strlen(prompt) * sizeof(char);
	/* 设置跳转点 */
	if(setjmp(env) < 0){
		perror("setjmp error");
	}
	write(STDOUT_FILENO, prompt, size);

	/* 从标准输入循环读取内容 */
	char buf[256];
	ssize_t len;
	while(1){
		len = read(STDIN_FILENO, buf, 256);
		if(len < 0)	
			break;
		buf[len - 1] = 0;
		do_line(buf);
		write(STDOUT_FILENO, prompt, size);
	}

	return 0;
}

void do_line(char *line){
	int cmd = get_token(line);
	switch(cmd){
		case TOK_ADD:
			cmd_add();
			break;
		case TOK_SUB:
			cmd_sub();
			break;
		default:
			fprintf(stderr, "error command\n");
	}
}

void cmd_add(void){
	int i = get_token(NULL);
	int j = get_token(NULL);
	printf("i:%d j:%d\n",i, j);
	printf("result is %d\n", i+j);
}

void cmd_sub(void){
	int i = get_token(NULL);
	int j = get_token(NULL);
	printf("i:%d j:%d\n",i, j);
	printf("result is %d\n", i-j);
}

static int is_number(char *item){
	int len = strlen(item);
	int i;
	for(i=0 ;i<len ;i++){
		if(item[i] > '9' || item[i] < '0')
			return 0;
	}
	return 1;
}

int get_token(char *line){
	/*
	 * add 3 4
	 * sub 5 7
	 */
	char *item = strtok(line, " ");
	if(line != NULL){
		if(!strcmp("add", item))	return TOK_ADD;
		if(!strcmp("sub", item))	return TOK_SUB;
	}else{
		if(is_number(item)){
			int i = atoi(item);
			return i;
		}else{
			fprintf(stderr, "arg not number\n");
			/* 进行非局部跳转 */
			longjmp(env, 1);
		}
	}
	
}
