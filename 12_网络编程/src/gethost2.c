/*
 * 文件名: gethost2.c
 * 描述: gethostent 函数的使用
 * 完成日期: 2018年3月1日 22:20
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

void out_addr(struct hostent *h)
{
	printf("hostname: %s\n", h->h_name);
	printf("addrtype: %s\n", h->h_addrtype == AF_INET ? "Ipv4" : "IPv6");
	char ip [16];
	memset(ip, 0, sizeof(ip));
	inet_ntop(h->h_addrtype, h->h_addr_list[0], ip, sizeof(ip));
	printf("ip address: %s\n", ip);
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s host\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct hostent *h;
	while((h = gethostent()) != NULL){
		if(!strcmp(argv[1], h->h_name)){
			out_addr(h);
			exit(0);
		}else{
			int i = 0;
			while(h->h_aliases[i] != NULL){
				if(!strcmp(argv[1], h->h_aliases[i])){
					out_addr(h);
					exit(0);
				}
				i++;
			}
		}
	}
	endhostent();
	printf("no %s exist\n", argv[1]); 

	return 0;
}
