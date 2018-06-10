/*
 * 文件名: cmd_pipe.c
 * 描述: cat /etc/passwd | grep root
 *		一个进程cat, 一个进程grep, 这两个进程都是父进程fork 出的子进程
 * 完成日期: 2018年2月24日7:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

char *cmd1[3] = {"/bin/cat", "/etc/passwd", NULL};
char *cmd2[3] = {"/bin/grep", "root", NULL};

int main(int argc, char *argv[])
{
	int fd[2];
	if(pipe(fd) < 0)
		handle_error("pipe error");

	pid_t pid;
	int i = 0;
	for(; i<2; i++){
		pid = fork();
		if(pid < 0){
			handle_error("fork error");
		}else if(pid == 0){
			if(i == 0){		// 第一个子进程,负责写入数据
				close(fd[0]);
				if(dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
					handle_error("dup2 error");
				close(fd[1]);
				if(execvp(cmd1[0], cmd1) < 0)
					handle_error("execvp error");
			}
			if(i == 1){		// 第二个子进程,负责读取数据
				close(fd[1]);
				if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
					handle_error("dup2 error");
				close(fd[0]);
				if(execvp(cmd2[0], cmd2) < 0)
					handle_error("execvp error");
			}
			break;
		}else{
			if(i == 1){
				close(fd[0]);
				close(fd[1]);
				wait(NULL);		// 父进程要等到子进程全部创建完毕才能回收
				wait(0);
			}
		}
	}

	return 0;
}
