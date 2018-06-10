#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int fd[2];

/* 管道初始化 */
void init_pipe(){
	if(pipe(fd) < 0){
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
}

/* 利用管道进行等待 */
void wait_pipe(){
	char c;
	if(read(fd[0], &c, 1) < 0){
		perror("wait_pipe error");
		exit(EXIT_FAILURE);
	}
}

/* 利用管道进行通知 */
void notify_pipe(){
	char c = 'c';
	if(write(fd[1], &c, 1) != 1){
		perror("notify_pipe error");
		exit(EXIT_FAILURE);
	}
}

/* 销毁管道 */
void destroy_pipe(){
	close(fd[0]);
	close(fd[1]);
}
