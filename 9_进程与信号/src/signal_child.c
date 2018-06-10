/*
 * 文件名: signal_child.c
 * 描述: signal 函数的使用, SIGCHLD 信号的介绍和使用
 * 完成日期: 2018年2月12日15:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signo){
	printf("child process deaded, signo: %d\n", signo);
	/* 当父进程捕获到 SIGCHLD 信号后要调用 wait 函数 
	 * 如果没有,在父进程存在期间,子进程成为僵尸进程*/
	wait(0);
}

void out(int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d out %d\n", getpid(), i);
		sleep(1);
	}
}

int main(void)
{
	if(signal(SIGCHLD, sig_handler) == SIG_ERR){
		perror("signal SIGCHLD error");
	}

	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}else if(pid > 0){
		out(20);
	}else{
		out(10);
	}

	return 0;
}
