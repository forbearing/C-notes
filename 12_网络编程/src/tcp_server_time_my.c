#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int sockfd;

void sig_handler(int signo){
	if(signo == SIGINT){
		printf("server close...\n");
		close(sockfd);
		exit(1);
	}
}

void out_addr(struct sockaddr_in *client){
	unsigned short port = ntohs(client->sin_port);
	char ip[16];
	if(inet_ntop(AF_INET, &client->sin_addr.s_addr, ip, sizeof(ip)) < 0)
		handle_error("inet_ntop error");
	printf("client: %s:%d connected\n", ip, port);
}

void do_server(int fd){
	time_t t = time(0);
	char *s = ctime(&t);
	size_t size = strlen(s);
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
	
	/* 2:bind */
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		handle_error("bind error");

	/* 3:listen */
	if(listen(sockfd, 10) < 0)
		handle_error("listen error");

	/* 4:accept */
	struct sockaddr_in client;
	memset(&client, 0, sizeof(client));
	socklen_t size = sizeof(client);
	while(1){
		int fd = accept(sockfd, (struct sockaddr*)&client, &size);
		if(fd < 0){
			perror("accept error");
			continue;
		}
		/* 5:与客户端进行通信 */
		out_addr(&client);
		do_server(fd);
		/* 6:关闭套接字 */
		close(fd);
	}

	return 0;
}
