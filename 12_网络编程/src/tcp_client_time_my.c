#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
	if(argc < 3){
		fprintf(stderr, "Usage: %s #ip #port\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* 1:创建 socket */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		handle_error("socket error");

	/* 2:connect */
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	if(inet_pton(AF_INET, argv[1], &addr.sin_addr.s_addr) < 0)
		handle_error("inet_pton error");
	if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		handle_error("connect error");

	/* 3:通信 */
	char buf[512];
	memset(buf, 0, sizeof(buf));
	size_t size;
	if((size = read(sockfd, buf, sizeof(buf))) < 0)
		handle_error("read error");
	if(write(STDOUT_FILENO, buf, size) != size)
		handle_error("write error");

	/* 4:关闭套接字 */
	close(sockfd);

	return 0;
}
