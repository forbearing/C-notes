/*
 * 文件名: front_group.c
 * 描述: 前台进程组
 *		默认是 group1 所在的进程为前台进程组, 现在将 group2 设置为前台进程组
 *		导致父进程(在 group1 中)就不能接受终端的 Ctrl-C 信号. 
 *		Ctrl-C 之后, 子进程消亡,父进程存在,导致出现僵尸进程
 * 完成日期: 2018年2月11日 15:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t group1, group2;
	setpgid(getpid(), getpid());
	group1 = getpgid(getpid());

	pid_t pid;
	int i = 0;
	for(; i<3; i++){
		if((pid = fork()) < 0){
			perror("fork error");
			exit(EXIT_FAILURE);
		}else if(pid > 0){
			if(i == 0){
				/* 创建进程组2, 第一个子进程作为组长进程 */
				setpgid(pid, pid);
				group2 = getpgid(pid);
			}
			if(i == 1){
				/* 将第二个子进程加入到 group2 */
				setpgid(pid, group2);
				/* 将 group2 设置为前台进程组 */
				tcsetpgrp(0, group2);
			}
			if(i == 2){
				/* 将第三个子进程加入到 group1 */
				setpgid(pid, group1);
			}
		}else{
			if(i == 0){
				/* 创建进程组2, 第一个子进程作为组长进程 */
				setpgid(getpid(), getpid());
				group2 = getpgid(getpid());
			}
			if(i == 1){
				/* 将第二个子进程加入到 group2 */
				setpgid(getpid(), group2);
				/* 将 group2 设置为前台进程组 */
				tcsetpgrp(0, group2);
			}
			if(i == 2){
				/* 将第三个子进程加入到 group1 */
				setpgid(getpid(), group1);
			}
			break;
		}
	}
	printf("pid:%d, ppid:%d, pgid:%d\n", getpid(), getppid(), getpgid(0));
	pause();

	return 0;
}
