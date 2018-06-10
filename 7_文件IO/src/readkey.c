/*
 * 文件名: readkey.c
 * 描述: 读取键盘输入, ioctl 函数的使用
 * 完成日期: 2018年2月3日
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/input.h>

int main(int argc, char *argv[])
{
	int fd = -1;
	char name[256] = "Unknow";
	struct input_event event;
	int ret = 0;

	if((fd = open("/dev/input/event4", O_RDONLY)) < 0){
		perror("open error");
		exit(EXIT_FAILURE);
	}

	if(ioctl(fd, EVIOCGNAME(sizeof(name)), name) < 0){
		perror("evdev ioctl error");
		exit(EXIT_FAILURE);
	}

	printf("The device says its name is %s\n", name);

	while(1){
		ret = read(fd, &event, sizeof(event));
		if(ret < 0)
			printf("read event error\n");
		if(EV_KEY == event.type){
			// If the event is a key code
			printf("key code is %d\n", event.code);
			if(event.code == 16)
				break;
		}
	}

	return 0;
}
