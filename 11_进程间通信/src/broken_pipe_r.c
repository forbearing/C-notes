/*
 * 文件名: broken_pipe_r.c
 * 描述: 不完整管道,写端关闭
 * 完成日期: 2018年2月24日 8:50
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(void)
{
	int fd[2];
	if(pipe(fd) < 0)
		handle_error("pipe error");


	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){	// 父进程负责读取

		/* 父进程从不完整管道(写端关闭)中读取数据 */
		sleep(2);		// 等子进程将管道关闭
		close(fd[1]);
		char c;
		ssize_t size;
		while(1){
			if((size = read(fd[0], &c, 1)) < 0){
				handle_error("read error");
			}else if(size == 0){
				printf("\nwrite-end of pipe closed\n");
				break;
			}else{
				printf("%c", c);
			}
		}
		close(fd[0]);
		wait(NULL);
		
	
	}else{				// 子进程负责写入

		close(fd[0]);
		char *s = "1234";
		if(write(fd[1], s, strlen(s)) != strlen(s))
			handle_error("write error");
		close(fd[1]);	// 关闭写端

	}

	return 0;
}
