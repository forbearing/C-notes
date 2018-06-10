/*
 * 文件名: cal_pipe.c
 * 描述: 管道的使用
 * 完成日期: 2018年2月23日 20:00
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	int fd[2];				// 父子进程中都有 fd[0] 和 fd[1]
	if(pipe(fd) < 0)
		handle_error("pipe error");

	pid_t pid;
	if(pid = fork() < 0){
		handle_error("fork error");
	}else if(pid > 0){		// 父进程写入数据
		close(fd[0]);
		int start = 1, end = 100;
		if(write(fd[1], &start, sizeof(int)) != sizeof(int))
			handle_error("write error");
		if(write(fd[1], &end, sizeof(int)) != sizeof(int))
			handle_error("write error");
		close(fd[1]);
		wait(0);
	}else{					// 子进程读取数据
		close(fd[1]);
		int start=0, end=0;
		if(read(fd[0], &start, sizeof(int)) < 0)
			handle_error("read error");
		if(read(fd[0], &end, sizeof(int)) < 0)
			handle_error("read error");
		close(fd[0]);
		printf("child process read start: %d, end: %d\n", start, end);
	}

	return 0;
}
