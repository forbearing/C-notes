#include <stdio.h>

//int a();					// 可以不用声明而直接使用,因为编译链接两个文件时,同
//static int b(int);		// 时编译进同一个可执行文件.

int main(void)
{
	a();
	//b(10);

	return 0;
}
