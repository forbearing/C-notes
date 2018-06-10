/*
 * Copyright (c) 我的有限公司
 * 文件名: clock.c
 * 描述: 时钟
 * 作者: Hyb
 * 完成日期: 2018年1月15日
 * 当期版本: 1.0
 */
 
#include <stdio.h>
#include <time.h>

typedef struct{
	int hour;
	int min;
	int sec;
}Clock;

void delay1();						// 定时1秒
void increment(Clock *p);			// 对小时,分钟,秒进行操作
void show(Clock *p);					// 显示时间

int main(void)
{
	Clock c = {12,0,55};
	int i;
	for(i=0; i<100; i++){
		delay1();
		increment(&c);
		show(&c);
	}

	return 0;
}

void delay1()
{
	time_t start, current;
	time(&start);
	do{
		time(&current);
	} while(current - start != 1);
}

void increment(Clock *p)
{
	p->sec++;
	if(p->sec == 60){
		p->sec = 0;
		p->min++;
		if(p->min == 60){
			p->min = 0;
			p->hour++; 
		}
	}
}

void show(Clock *p)
{
	printf("\033[2J");			// 清屏
	printf("%02d:%02d:%02d\n", p->hour, p->min, p->sec);
}
