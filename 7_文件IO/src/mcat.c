/*
 * 文件名: mcat.c
 * 描述: dup2 函数实现重定向
 *		bin/mcat + file (+ 为输入重定向))
 *		bin/mcat - file	(- 为输出重定向)
 * 完成日期: 2018年2月1日16:37
 */

#include "io.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd_in ,fd_out;
	int flag = 0;

	int i;
	for(i=1; i<argc; i++){
		if(!strcmp("+", argv[i])){
			fd_in = open(argv[++i], O_RDONLY);
			if(fd_in < 0){
				perror("open error");
				exit(EXIT_FAILURE);
			}
			// 将标准输入重定向到文件
			if(dup2(fd_in, STDIN_FILENO) !=STDIN_FILENO){
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
			close(fd_in);
		}else if(!strcmp("-", argv[i])){
			fd_out = open(argv[++i], O_WRONLY|O_CREAT|O_TRUNC, 0777);
			if(fd_out < 0){
				perror("open error");
				exit(EXIT_FAILURE);
			}
			// 将标准输出重定向到文件
			if(dup2(fd_out, STDOUT_FILENO) != STDOUT_FILENO){
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
			close(fd_out);
		}else{
			flag = 1;
			fd_in = open(argv[i], O_RDONLY);
			if(fd_in < 0){
				perror("open error");
				exit(EXIT_FAILURE);
			}
			if(dup2(fd_in, STDIN_FILENO) !=STDIN_FILENO){
				perror("dup2 error");
				exit(EXIT_FAILURE);
			}
			copy(STDIN_FILENO, STDOUT_FILENO);
			close(fd_in);
		}
	}

	if(!flag){
		copy(STDIN_FILENO, STDOUT_FILENO);
	}

	return 0;
}
