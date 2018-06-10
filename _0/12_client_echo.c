/*
 * 文件名: client_echo.c
 * 描述: 服务器端和客户端进行双线通信, 客户端代码
 * 完成日期: 2018年2月28日 19:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
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
		buf[size -1]=  '\0';

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

	return 0;
}
