#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char*argv[])
{

	srand((unsigned int)time(NULL));
	for(int i=0; i<5; i++)
		printf("%5.3f\n", drand48()*pow(2,47));

	exit(EXIT_SUCCESS);
}

