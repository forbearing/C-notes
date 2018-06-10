/*
 * 文件名: system.c
 * 描述: system 函数的使用
 * 完成日期: 2018年2月9日 20:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *cmd1 = "ls /etc/apt";

void mysystem(char *cmd){
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		if(execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL) < 0){
			perror("execlp error");
			exit(1);
		}
	}else{
		wait(NULL);
	}
}

int main(void)
{
	system("clear");
	system(cmd1);
	mysystem(cmd1);

	return 0;
}
