/*
 * 文件名: prompt.c
 * 描述: 提示符
 * 完成日期: 2018年2月5日19:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void do_line(char *line);

int main(void)
{
	char *prompt = "->: ";
	ssize_t size = sizeof(prompt) * sizeof(char);
	write(STDOUT_FILENO, prompt, size);

	char buf[256];
	ssize_t len;
	while(1){
		len = read(STDIN_FILENO, buf, sizeof(buf));
		if(len < 0)	break;
		do_line(buf);
		write(STDOUT_FILENO, prompt, size);
	}

	return 0;
}

void do_line(char *line){}
