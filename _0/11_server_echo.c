/*
 * 文件名: tcp_echo.c
 * 描述: 服务器端和客户端进行双向通信, 服务器端代码
 * 完成日期: 2018年2月28日 17:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void do_service(int fd)
{
	char buf[512];
	size_t size;
	while(1){
		memset(buf, 0, sizeof(buf));
		printf("start read and write\n");
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
