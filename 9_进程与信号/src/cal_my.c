/*
 * 文件名: cal.c
 * 描述: 简单的计算器,复杂的代码
 * 完成日期: 2018年2月5日20:10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define ADD 1
#define SUB 2
#define BUF_SIZE 1024

char *prompt = "->: ";

void do_line(char *line);
int get_token(char *line);
void add(void);
void sub(void);
static int is_number(char *item);

int main(void)
{
	/* 输出提示符 */
	ssize_t size = strlen(prompt) * sizeof(char);
	write(STDOUT_FILENO, prompt, size);

	char buf[BUF_SIZE];
	ssize_t len;
	memset(buf, 0, sizeof(buf));
	/* 循环处理从终端读取的内容 */
	while(1){
		len = read(STDIN_FILENO, buf, sizeof(buf));
		if(len < 0){
			printf("read error");
			break;
		}
		do_line(buf);
		write(STDOUT_FILENO, prompt, size);
	}

	return 0;
}

void do_line(char *line){
	int cmd = get_token(line);
	switch(cmd){
		case ADD:
			add();
			break;
		case SUB:
			sub();
			break;
		default:
			fprintf(stderr,"error command\n");
			break;
	}
}

int  get_token(char *line){
	char *item = strtok(line, " ");
	if(line != NULL){
		if(!strcmp("add", item))	return ADD;
		if(!strcmp("sum", item))	return SUB;
	}else{
		if(is_number(item) < 0){
			int i = atoi(item);
			return i;
		}else
			fprintf(stderr, "error command");
	}
}

static int is_number(char *item)
{
	int len = strlen(item);
	int i;
	for(i=0; i<len; i++){
		if(item[i] > '9' || item[i] < '0')
			return -1;
	}
	return 0;
}

void add(void){
	int i = get_token(NULL);
	int j = get_token(NULL);
	printf("result: %d\n", i+j);
}
void sub(void){
	int i = get_token(NULL);
	int j = get_token(NULL);
	printf("result: %d\n", i-j);
}
