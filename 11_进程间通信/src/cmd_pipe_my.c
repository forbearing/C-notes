/*
 * 文件名: cmd_pipe.c
 * 描述: cat /etc/passwd | grep root
 * 完成日期: 2018年2月24日 7:40
 * 注意: 父进程中, 先close, 在wait
 *		close(fd[0]);
 *		close(fd[1]);
 *		wait(0);
 *		wait(0);
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

char *cmd1[3] = {"/bin/cat", "/etc/passwd", NULL};
char *cmd2[3] = {"/bin/grep", "root", NULL};

int main(void)
{
	int fd[2];
	if(pipe(fd) < 0)
		handle_error("pipe error");

	pid_t pid;
	int i;
	for(i=0; i<2; i++){

		 if((pid = fork()) < 0){
			handle_error("fork error");
		 }else if(pid > 0){

			if(i == 1){
				close(fd[0]);
				close(fd[1]);
				wait(0);
				wait(0);
			}

		 }else{

			if(i == 0){		// 写入数据
				close(fd[0]);
				if(dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
					handle_error("dup2 error");
				close(fd[1]);
				if(execvp(cmd1[0], cmd1) < 0)
					handle_error("execvp error");
				break;
			}

			if(i == 1){		// 读取数据
				close(fd[1]);
				if(dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
					handle_error("dup2 error");
				close(fd[0]);
				if(execvp(cmd2[0], cmd2) < 0)
					handle_error("execvp error");
				break;
			}

			//break;
		 }
	}

	exit(EXIT_SUCCESS);
}
