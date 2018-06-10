/*
 * 文件名: process_group.c
 * 描述: 进程组的介绍.  getpgid, setpgid 的使用
 * 完成日期: 2018年2月10日 9:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	/* 创建组长进程, 组长进程为父进程 */
	setpgid(getpid(), getpid());
	pid_t group1 = getpid();
	//pid_t group1 = getpgid(0);
	//pid_t group1 = getpgid(getpid());
	//pid_t group1 = getpgrp();
	pid_t group2;

	int i = 0;
	pid_t pid;
	for(; i<3; i++){
		pid = fork();
		if(pid < 0){
			perror("fork error");
			exit(EXIT_FAILURE);
		}else if(pid > 0){
			/* 父进程中执行和子进程相同的操作 */
			if(i == 0){
				setpgid(pid, group1);
			}
			if(i == 1){
				/* 创建进程组,第二个子进程作为组长进程 */
				setpgid(pid, pid);
				group2 = getpgid(pid);
			}
			if(i == 2){
				/* 第三个子进程加入到 group2 中 */
				setpgid(getpid(), group2);
			}
		}else{
			if(i == 0){
				/* 将第一个子进程加入到 group1 中 */
				setpgid(getpid(), group1);
			}
			if(i == 1){
				setpgid(getpid(), getpid());
				group2 = getpgid(getpid());
			}
			if(i == 2){
				setpgid(getpid(), group2);
			}
			/* 因为是进程扇,每个子进程要退出循环. 父进程继续循环fork() */
			break;
		}
	}
	printf("pid: %d, ppid:%d, pgid:%d\n", getpid(), getppid(), getpgid(0));
	for(i=0; i<3; i++){
		wait(0);
	}

	return 0;
}
