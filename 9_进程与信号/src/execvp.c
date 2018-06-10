/*
 * 文件名: execvp.c
 * 描述: execvp 函数的使用
 * 完成日期; 2018年2月9日20:30
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

char *cmd1 = "cat";
char *cmd2 = "/bin/cat";
char *argv1 = "/etc/shells";
char *argv2 = "/etc/hostname";

int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0){
		handle_error("fork error");
	}else if(pid == 0){
		char *argv[4] = {cmd1, argv1, argv2, NULL};
		if(execvp(cmd1, argv) < 0)
			handle_error("execvp error");
		else
			printf("execvp %s success\n", cmd1);
	}else{
		wait(0);
		wait(NULL);
	}

	return 0;
}
