/*
 * 文件名: msg_snd.c
 * 描述: 消息队列--发送消息
 * 完成日期: 2018年2月24日 22:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>

#define handle_error(msg)	\
	do { perror(msg); exit(EXIT_FAILURE); } while(0)

typedef struct{
	long	type;
	int		start;
	int		end;
}MSG;

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s key\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	key_t key = atoi(argv[1]);
	//key_t key = IPC_PRIVATE
	//key_t key = ftok(argv[1], 0); 
	printf("key: %d\n", key);


	/* 创建消息队列 */
	int msqid;
	if((msqid = msgget(key, IPC_CREAT|IPC_EXCL|0777)) < 0)
		handle_error("msgget error");
	printf("msqid is: %d\n", msqid);

	/* 定义要发送的消息 */
	MSG m1 = {1, 1, 100};
	MSG m2 = {2, 2, 200};
	MSG m3 = {3, 3, 300};
	MSG m4 = {4, 4, 400};

	/* 发送消息 */
	if(msgsnd(msqid, &m1, sizeof(MSG)-sizeof(long), IPC_NOWAIT) < 0)
		handle_error("msgsnd error");
	if(msgsnd(msqid, &m2, sizeof(MSG)-sizeof(long), IPC_NOWAIT) < 0)
		handle_error("msgsnd error");
	if(msgsnd(msqid, &m3, sizeof(MSG)-sizeof(long), IPC_NOWAIT) < 0)
		handle_error("msgsnd error");
	if(msgsnd(msqid, &m4, sizeof(MSG)-sizeof(long), IPC_NOWAIT) < 0)
		handle_error("msgsnd error");

	/* 获取消息队列中消息的总数 */
	struct msqid_ds ds;
	if(msgctl(msqid, IPC_STAT, &ds) < 0)
		handle_error("msgctl error");
	printf("msg total: %ld\n", ds.msg_qnum);

	return 0;
}
