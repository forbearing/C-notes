/*
 * 文件名: msg.c
 * 描述: 自定义协议
 * 完成日期: 2018年2月28日 10:20
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "msg.h"

static unsigned char msg_check(Msg *message){
	unsigned char s = 0;
	int i;
	for(i=0; i<sizeof(message->head); i++)
		s += message->head[i];
	for(i=0; i<sizeof(message->buf); i++)
		s += message->buf[i];
	return s;
}

/* 发送一个基于自定义协议的message, 发送的数据存放在buf 中 */
int write_msg(int sockfd, char *buf, size_t len)
{
	Msg message;
	memset(&message, 0, sizeof(message));
	strcpy(message.head, "iotek2012");
	memcpy(message.buf, buf, len);
	message.checknum = msg_check(&message);
	if(write(sockfd, &message, sizeof(message)) != sizeof(message)){
		perror("write error");
		return -1;
	}
	return 0;
}

/* 接受一个基于自定义协议的message, 接受的数据存放在buf 中 */
int read_msg(int sockfd, char *buf, size_t len)
{
	Msg message;
	memset(&message, 0, sizeof(message));
	size_t size;
	if((size =  read(sockfd, &message, sizeof(message))) < 0)
		return -1;
	else if(size == 0)
		return 0;
	unsigned char s = msg_check(&message); 
	if((s == (unsigned char)message.checknum) && 
				(!strcmp("iotek2012",message.head))){	// 校验码验证
		memcpy(buf, message.buf, len);
		return sizeof(message);
	}
	return -1;
}
