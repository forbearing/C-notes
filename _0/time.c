#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char*argv[])
{
	time_t t;
	time(&t);
	printf("%s\n", ctime(&t));

	exit(EXIT_SUCCESS);
}

