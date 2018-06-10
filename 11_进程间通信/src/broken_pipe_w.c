/*
 * 文件名: broken_pipe_w.c
 * 描述: 不完整管道, 读端关闭
 * 完成日期: 2018年2月24日 9:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

void sig_handler(int signo){
	if(signo == SIGPIPE)
		printf("SIGPIPE occured\n");
}

int main(void)
{
	int fd[2];
	if(pipe(fd) < 0)
		handle_error("pipe error");


	pid_t pid = fork();
	if(pid < 0){
		handle_error("fork error");
	}else if(pid > 0){		// 父进程写入数据

		sleep(2);			// 等待子进程关闭管道读端
		close(fd[0]);
		if(signal(SIGPIPE, sig_handler) == SIG_ERR)
			handle_error("signal error");
		char *s = "1234";
		if(write(fd[1], s, strlen(s)) != strlen(s)){
			fprintf(stderr, "%s, %s\n", strerror(errno), 
					(errno == EPIPE) ? "EPIPE" : "Unknow");
		}
		close(fd[1]);
		wait(NULL);
	
	}else{

		close(fd[0]);		// 子进程关闭管道的读端
		close(fd[1]);

	}
	
	return 0;
}
