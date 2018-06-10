/*
 * 文件名: udp_server_time.c
 * 描述: udp编程, 服务器端代码
 * 完成日期: 2018年2月28日 20:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int sockfd;

void sig_handler(int signo){
	if(signo == SIGINT){
		printf("server close\n");
		close(sockfd);
		exit(1);
	}
}

void out_addr(struct sockaddr_in *clientaddr){
	char ip[16];
	memset(ip, 0, sizeof(ip));
	inet_ntop(AF_INET, &clientaddr->sin_addr.s_addr, ip, sizeof(ip));
	int port = ntohs(clientaddr->sin_port);
	printf("client: %s(%d)\n", ip, port);
}

void do_service(){
	struct sockaddr_in clientaddr;
	socklen_t len = sizeof(clientaddr);
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	if(recvfrom(sockfd, buf, sizeof(buf), 0,			// 接受客户端数据报文
				(struct sockaddr*)&clientaddr, &len) < 0){
		handle_error("recvfrom error");
	}else{
		out_addr(&clientaddr);
		printf("client send info: %s\n", buf);
		long t = time(0);
		char *ptr = ctime(&t);
		size_t size = strlen(ptr) * sizeof(char);
		if(sendto(sockfd, ptr, size, 0,					// 向客户端发送数据报文
					(struct sockaddr*)&clientaddr, len) < 0)
			handle_error("sendto error");
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s #port\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(signal(SIGINT, sig_handler) == SIG_ERR)
		handle_error("signal error");

	/* 1:创建socket */
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		handle_error("socket error"); 

	/* 设置套接字选项 */
	int ret;
	int opt = 1;
	if((ret = setsockopt(sockfd, SOL_SOCKET, 
					SO_REUSEADDR, &opt, sizeof(opt))) < 0)
		handle_error("setsock opt error");

	/* 2:调用bind 函数对socket 和地址进行绑定 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[1]));
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
		handle_error("bind error");

	/* 3:与客户端进行双向通讯 */
	while(1){
		do_service();
	}

	return 0;
}
