/*
 * 文件名: file_dev.c
 * 描述: 输出特殊设备文件的主次设备号
 * 完成日期: 2018年2月5日22:20
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>

#define handle_error(msg)	\
	do { perror(msg); continue; } while(0)

void out_dev(dev_t devno){
	/* 生成主设备号和次设备号 */
	int mj = major(devno);
	int mi = minor(devno);
	printf("%5d, %5d", mj, mi);
}

int main(int argc, char *argv[])
{
	if(argc < 2){
		fprintf(stderr, "Usage: %s file\n",argv[0]);
		exit(EXIT_FAILURE);
	}

	struct stat buf;
	int i;

	for(i=1; i<argc; i++){
		/* 判断文件是否存在 */
		if(access(argv[i], F_OK) < 0){
			printf("%s not exist\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		memset(&buf, 0 ,sizeof(buf));			// 获取文件属性结构体
		if(lstat(argv[i], &buf) < 0)
			handle_error("lstat error");
		printf("%-20s", argv[i]);

		/* 判断是否是字符设备文件和块设备文件 */
		if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)){
			printf("device file: ");
			/* 输出特殊设备文件才具有的特殊设备号(包括主,次设备号) */
			out_dev(buf.st_rdev);
		}
		printf("	on: ");
		/* 输出所有文件都具有的设备号(包括主,次设备号) */
		out_dev(buf.st_dev);
		printf("\n");
	}

	return 0;
}
