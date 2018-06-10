/*
 * 文件名: tcp_client_echo.c
 * 描述: 基于自定义协议多进程模型的客户端编程
 * 完成日期: 2018年2月28日 9:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "msg.h"

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s ip port\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1:创建socket */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		handle_error("socket error");

	/* 2:调用connect 函数连接到服务器端 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[2]));
	if(inet_pton(AF_INET, argv[1], &serveraddr.sin_addr.s_addr) < 0)
		handle_error("inet_pton error");
	if(connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
		handle_error("connect error");

	/* 3:调用IO 函数(read/write) 和服务器端进行双向通信 */
	char buf[512];
	size_t size;
	char *prompt = ">";
	while(1){
		memset(buf, 0, sizeof(buf));
		write(STDOUT_FILENO, prompt, 1);
		size = read(STDIN_FILENO, buf, sizeof(buf));
		if(size < 0){
			perror("read error");
			continue;
		}
		buf[size-1] = '\0';

		if(write_msg(sockfd, buf, sizeof(buf)) < 0){
			perror("write_msg error");
			continue;
		}else{
			if(read_msg(sockfd, buf, sizeof(buf)) < 0){
				perror("read_msg error");
				continue;
			}else{
				printf("%s\n", buf);
			}
		}
	}

	/* 4:关闭套接字 */
	close(sockfd);

	return 0;
}
