/* * Copyright (c) 我的有限公司
 * 文件名: calculator.c
 * 描述: 完成一个计算器
 * 作者: hyb
 * 完成日期: 2017年12月25日
 * 当前版本: 1.0
 */

#include <stdio.h>
#include "mymath.h"

int get_option();
void print_result(int num1, int num2, int result, int option);

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
				printf("\nPlease input two number: ");
				scanf("%d %d", &num1, &num2);
				if(option == 4 && num2 == 0){
					printf("\n*** Error *** ");
					printf("Second number can not be 0\n");
				}
			}while(option == 4 && num2 == 0);

			switch(option){
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
			} // end of switch
			print_result(num1, num2, result, option);
		} // end of if-else
	} // end of whle

	return 0;
}

/*
 * 函数名称: get_option
 * 描述: 获得计算器菜单的选项
 * 作者: hyb
 * 完成日期: 2017年12月25日
 * 输入: 无
 * 输出: 选择的整型菜单选项
 * 当前版本: 1.0
 */
int get_option()
{
	int option;

	do{
		printf("\n**********************");
		printf("\n*         MENU       *");
		printf("\n*                    *");
		printf("\n*     1. ADD         *");
		printf("\n*     2. SUBTRACT    *");
		printf("\n*     3. MULTIPLY    *");
		printf("\n*     4. DIVIDE      *");
		printf("\n*     5. QUIT        *");
		printf("\n*                    *");
		printf("\n**********************");

		printf("\nPlease input your choice: ");
		scanf("%d", &option);
		if(option < 1 || option > 5)
			printf("Invalid option, Please re-enter.\n");
	}while(option < 1 || option > 5);
	
	return option;
}

/*
 * 函数名称: print_result
 * 描述: 在屏幕上输出进行操作的两个数及结果
 * 作者: Hyb
 * 完成日期: 2017年12月25日
 * 输入: 整型的两个操作数,计算结果和菜单选项
 * 返回: 无
 * 当前版本: 1.0
 */
void print_result(int num1, int num2, int result, int option)
{
	char operator;
	switch(option){
		case 1:
			operator = '+';
			break;
		case 2:
			operator = '-';
			break;
		case 3:
			operator = '*';
			break;
		case 4:
			operator = '/';
			break;
	}	// end of switch
	printf("\n** %d %c %d = %d\n", num1, operator, num2, result);
}
