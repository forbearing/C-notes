/*
 * 文件名: mysystem.c
 * 描述: 自己实现 system 函数
 * 完成日期: 2018年2月9日 20:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *cmd = "date";

int main(void)
{
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		//if(execlp("/bin/bash -c", "/bin/bash -c", cmd, NULL) < 0){	错误
		if(execlp("/bin/bash", "/bin/bash", "-c", cmd, NULL) < 0){
			perror("execlp error");
			exit(EXIT_FAILURE);
		}
	}else{
		wait(NULL);
	}

	return 0;
}
