/* 
 * 文件名: rand.c
 * 描述: 产生各类随机数
 * 完成日期: 2018/05/31 11:00
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char*argv[])
{
	int i;
	srand((unsigned)time(NULL));
	printf("RAND_MAX: %d\n",RAND_MAX);
	printf("\n");

	/* 产生 5 个随机数 */
	printf("产生 5 个随机数\n");
	for(i=0; i<5; i++)
		printf("%d\n", rand());
	printf("\n");

	/* 产生5个0-1 之间的随机数 */
	printf("产生 5 个 0-1 随机数\n");
	for(i=0; i<5; i++)
		printf("%5.3f\n", rand()/pow(2,31));
	printf("\n");

	/* 产生5个1-100 之间的随机数 */
	printf("产生 5 个 1-100 之间的随机数\n");
	for(i=0; i<5; i++)
		printf("%d\n", (int)(rand()/pow(2,31)*100+1));
	printf("\n");

	exit(EXIT_SUCCESS);
}

