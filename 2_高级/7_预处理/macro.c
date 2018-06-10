#include <stdio.h>

#define PRINT(FORMAT, VALUE) printf("the value: " FORMAT "\n", VALUE)
#define HELLO "hello linux"
#define PRINT2(INFO) printf("Welcome %s and %s", INFO, HELLO)

int main(void)
{
	int x = 10;
	PRINT("%d", x);
	PRINT2("hyb");

	return 0;
}
