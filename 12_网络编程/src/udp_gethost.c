/*
 * 文件名: udp_gethost.c
 * 描述: udp 编程, 客户端代码, gethostbyname 的使用
 * 完成日期: 2018年3月1日 22:50
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

unsigned int get_ip_by_name(char *name)
{
}

int main (int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s ip port\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1:创建 socket */
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
		handle_error("socket error");

	/* 2:和客户端进行双向通信 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[2]));
	//inet_pton(AF_INET, argv[1], &serveraddr.sin_addr.s_addr);
	unsigned int ip = get_ip_by_name(argv[1]);
	if(ip != 0){
		serveraddr.sin_addr.s_addr = ip;
	}else{
		inet_pton(AF_INET, argv[1], &serveraddr.sin_addr.s_addr);
	}
	char buf[1024] = "hello iotek";
	if(sendto(sockfd, buf, sizeof(buf), 0,		// 向服务器端发送数据报文
					(struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		handle_error("sendto error");
	}else{
		memset(buf, 0, sizeof(buf));
		if(recv(sockfd, buf, sizeof(buf), 0) < 0)
			handle_error("recv error");
		else
			printf("%s", buf);
	}
	return 0;
}
