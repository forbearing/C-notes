#include <stdio.h>
#include "mymath.h"

int get_option();
void print_result(int option, int num1, int num2, int result);

int main(void)
{
	int done = 0;
	int option, num1, num2, result;
	while(!done){
		option = get_option();

		if(option == 5){
			done = 1;
		}else{
			do{
				printf("please input two number: ");
				scanf("%d %d", &num1, &num2);
				if(option == 4 && num2 == 0)
					printf("ERROR, num2 cat not be 0\n");
			}while(option == 4 && num2 == 0);
			switch (option){
				case 1:
					result = add(num1, num2);
					break;
				case 2:
					result = sub(num1, num2);
					break;
				case 3:
					result = mul(num1, num2);
					break;
				case 4:
					result = div(num1, num2);
					break;
			}// end switch
			print_result(option, num1, num2, result);
		}// end if-else
	}// end while

	return 0;
}


int get_option()
{
	int option;
	do{
		printf("\n******************");
		printf("\n*      MENU      *");
		printf("\n*     1: ADD     *");
		printf("\n*     2: SUB     *");
		printf("\n*     3: MUL     *");
		printf("\n*     4: DIV     *");
		printf("\n*     5: QUIT    *");
		printf("\n*                *");
		printf("\n******************");

		printf("\nplease input your option: ");
		scanf("%d", &option);
		if(option < 1 || option > 5)
			printf("input ERROR, re-input\n");
	}while(option < 1 || option > 5);
	
	return option;
}

void print_result(int option, int num1, int num2, int result)
{
	char ch;
	switch (option){
		case 1:
			ch = '+';
			break;
		case 2:
			ch = '-';
			break;
		case 3:
			ch = '*';
			break;
		case 4:
			ch = '/';
			break;
	}
	printf("%d %c %d = %d", num1, ch, num2, result);
}
