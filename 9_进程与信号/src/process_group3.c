/*
 * 文件名: process_group3.c
 * 描述: kill -9 -进程组ID
 * 完成日期: 2018年2月10日 9:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0){
		perror("fork error");
		exit(1);
	}else if(pid > 0){
		setpgid(pid, getpgid(0));
	}else{
		setpgid(getpid(), getppid());
	}

	printf("pid:%d, ppid:%d, pgid:%d\n", getpid(), getppid(), getpgid(0));

	pause();

	return 0;
}
