/*
 * 文件名: process_wait.c
 * 描述: wait 函数的使用
 * 完成日期: 2018年2月9日 9:10
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void out_status(int status){
	printf("status: %d\n", status);
	if(WIFEXITED(status)){
		printf("normal exit: %d\n", WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)){
		printf("abormal tem: %d\n", WTERMSIG(status));
	}else if(WIFSTOPPED(status)){
		printf("stopped sig: %d\n", WSTOPSIG(status));
	}else{
		printf("unknow sig\n");
	}
}

int main(void)
{
	int status;
	pid_t pid = fork();
	if(pid < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
		exit(2);
	}
	// 父进程阻塞,等待子进程结束并回收
	wait(&status);
	out_status(status);
	printf("---------------------------------\n");

	if((pid = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
		int i=3, j=0;
		int k = i/j;
		printf("k: %d\n", k);
	}
	wait(&status);
	out_status(status);
	printf("---------------------------------\n");

	if((pid = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		printf("pid: %d, ppid: %d\n", getpid(), getppid());
		pause();
	}
/*
	do{
		pid = waitpid(pid, &status, WUNTRACED|WNOHANG);
		if(pid == 0)	sleep(1);
	} while(pid == 0);
*/	waitpid(pid, &status, WUNTRACED);
	out_status(status);

	exit(EXIT_SUCCESS);
}
