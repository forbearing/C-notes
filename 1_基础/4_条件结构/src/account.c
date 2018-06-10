/*
 * Copyright (c) 我的有限公司
 * 文件名: account.c
 * 描述: 开发一个程序操作用户的账户,程序万将为用户提供清空账户余额(clear),
 *		 存款(deposit), 取款(withdraw), 显示当前账户余额(balance) 
 *		 和退出程序(exit)
 * 作者: hyb
 * 完成日期: 2017年12月19日
 * 当前版本: 1.0
 */

#include <stdio.h>

int main(void)
{
	int cmd;
	float balance = 0.0f, deposit, withdraw;
	printf("*** ACME checkbook-balanceing program ***\n");
	printf("Commands: 0=clear, 1=deposit, 2=withdraw, 3=balance 4=exit\n\n");

	while(1){
		printf("Enter command: ");
		scanf("%d", &cmd);
		switch(cmd){
			case 0:				// 清空账户
				balance = 0.0f;
				break;
			case 1:				// 存款
				printf("Enter amount of deposit: \n");
				scanf("%f",&deposit);
				balance = balance + deposit;
				break;
			case 2:				// 取款
				printf("Enter amount of withdraw: \n");
				scanf("%f", &withdraw);
				balance = balance - withdraw;
				break;
			case 3:				// 查看当前账户余额
				printf("Current balance: $%.2f\n",balance);
			case 4:				// 结束 main 函数运行
				return 0;
			default:
				printf("Commands: 0=clear, 1=deposit, 2=withdraw, 3=exit\n\n");
				break;
		}
	}

	return 0;
}
