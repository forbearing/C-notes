/*
 * 文件名: exec.c
 * 描述: exec 系列函数)的使用
 *		 execl, execv, execle, execve, execlp, execvp
 * 完成日期: 2018年2月9日 20:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do{ perror(msg); exit(EXIT_FAILURE); } while(0)

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
		/* 子进程调用 exec 函数执行新的程序 */
		//if(execl(cmd2, "wokao", argv1, argv2, NULL) < 0)		// 成功
		if(execl(cmd2, "cmd1", argv1, argv2, NULL) < 0)			// 标准
		//if(execl(cmd1, cmd1, argv1, argv2, NULL) < 0)			// 失败
			handle_error("execl error");
		else
			printf("exec %s success\n", cmd1);
		printf("after execl\n");		// exec 成功返回后,后面的代码不执行
	}else{
		//wait(NULL);
	}

	wait(NULL);
	printf("---------------------------------\n");

	return 0;
}
