/*
 * 文件名: time_server_time.c
 * 描述: 先启动一个服务器端,再启动一个客户端,客户端连接服务器端,服务器端返回一个
 bNext*		系统时间
 * 完成日期; 2018年2月27日
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int sockfd;

void sig_handler(int signo){
	if(signo == SIGINT){
		printf("server close\n");
		close(sockfd);			// 6:关闭套接字   
		exit(1);
	}
}

void out_addr(struct sockaddr_in *clientaddr){	// 输出连接上来的客户端相关信息
	int port = ntohs(clientaddr->sin_port);
	char ip[16];
	memset(ip, 0, sizeof(ip));
	if(inet_ntop(AF_INET, &clientaddr->sin_addr.s_addr, ip, sizeof(ip)) < 0)
		handle_error("inet_ntop error");
	printf("client: %s(%d) connected\n", ip, port);
}

void do_service(int fd){
	long t = time(0);
	char *s = ctime(&t);
	size_t size = strlen(s) * sizeof(char);
	if(write(fd, s, size) != size)
		handle_error("write error");
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s #port\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if(signal(SIGINT, sig_handler) == SIG_ERR)
		handle_error("signal error");
	
	/* 1:创建套接字 */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		handle_error("socket error");

	/* 2:调用bind 函数将socket 和地址(包括ip, port)进行绑定 */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[1]));
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
		handle_error("bind error");

	/* 3:调用 listen 函数启动监听(指定port 监听), 通知系统接收来自客户端的请求
	 * 将接受到的客户端连接请求放置到对应的队列中. 第二个参数: 指定队列的长度 */
	if(listen(sockfd, 10) < 0)
		handle_error("listen error");

	/* 4:调用accpet 函数从队列中获得一个客户端的请求连接,
	 * 若没有客户端连接,调用此函数后会阻塞,直到获得一个客户端连接*/
	struct sockaddr_in clientaddr;
	socklen_t clientaddr_len = sizeof(clientaddr);
	while(1){
		int fd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddr_len);
		if(fd < 0){
			perror("accept error");
			continue;
		}
		/* 5:调用IO 函数(read/write) 和连接的客户端进行双向通信 */
		out_addr(&clientaddr);
		do_service(fd);

		/* 6:关闭套接字 */ 
		close(fd);
	}
	

	return 0;
}
