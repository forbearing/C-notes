/*
 * 文件名: time_server_th.c
 * 描述: 基于自定义协议多线程模型的服务器编程
 * 完成日期; 2018年2月28日 20:00
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
#include <errno.h>
#include <pthread.h>
#include "msg.h"

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

void do_service(int fd){
	char buf[512];				// 和客户端进行双向通信
	while(1){
		memset(buf, 0, sizeof(buf));
		printf("start read and write\n");
		size_t size;
		if((size = read_msg(fd, buf, sizeof(buf))) < 0){
			perror("protocol error");
			break;
		}else if(size == 0){
			printf("client closed\n");
			break;
		}else{
			printf("%s\n", buf);
			if(write_msg(fd, buf, sizeof(buf)) < 0){
				perror("protocol error");
				break;
			}else if(errno == EPIPE){
				printf("client closed\n");
				break;
			}
		}
	}
}


void out_fd(int fd){		// 通过套接字获取客户端信息
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	if(getpeername(fd, (struct sockaddr*)&addr, &len) < 0){
		perror("getpeername error");
		return;
	}
	char ip[16];
	memset(ip, 0, sizeof(ip));
	unsigned short port = ntohs(addr.sin_port);
	if(inet_ntop(AF_INET, &addr.sin_addr.s_addr, ip, sizeof(ip)) < 0)
		handle_error("inet_ntop error");
	printf("%16s(%5d) closed!\n", ip, port);
}

void* th_fn(void *arg){
	int fd = (int)arg;
	out_fd(fd);
	do_service(fd);
	close(fd);
	return (void*)0;
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

	/* 2:bind */
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[1]));
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0)
		handle_error("bind error");

	/* 3:listen */
	if(listen(sockfd, 10) < 0)
		handle_error("listen error");

	/* 4:accept */
	pthread_attr_t attr;				// 设置线程的分离属性
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	while(1){
		int fd = accept(sockfd, NULL, NULL);
		if(fd < 0){
			perror("accept error");
			continue;
		}
		/* 5:分离方式启动子线程调用IO 函数(read/write) 和客户端进行双向通信 */ 
		pthread_t th;
		if(pthread_create(&th, &attr, th_fn, (void*)fd) != 0)
			handle_error("pthread_create error");
		pthread_attr_destroy(&attr);
	}
	
	return 0;
}
