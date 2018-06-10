/*
 * 文件名: gethost.c
 * 描述: 域名解析
 * 完成日期: 2018年3月1日 7:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

void out_addr(struct hostent *h){
	printf("hostname: %s\n", h->h_name);
	printf("addrtype: %s\n", h->h_addrtype == AF_INET ? "IPv4":"IPv6");
	char ip[16];
	memset(ip, 0, sizeof(ip));
	inet_ntop(h->h_addrtype, h->h_addr_list[0], ip, sizeof(ip));
	printf("ip address: %s\n", ip);

	int i = 0;
	while(h->h_aliases[i] != NULL){
		printf("alias: %s\n", h->h_aliases[i]);
		i++;
	}
	
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s host\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	struct hostent *h;
	h = gethostbyname(argv[1]);
	if(h != NULL){
		out_addr(h);
	}else{
		printf("no %s exist\n", argv[1]);
	}
	

	return 0;
}
