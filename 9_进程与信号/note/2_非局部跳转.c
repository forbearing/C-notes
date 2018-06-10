1:setjmp 和 longjmp 函数
	#include <setjmp.h>
	int setjmp(jmp_buf env);
	1:返回: 直接调用返回0, 若从 longjmp 调用返回非0值
	2:功能: 设置非局部跳转的跳转点
	void longjmp(jmp_buf env, int val)
	1:功能: 进行非局部跳转, val 为返回值
	2:env 参数
		一个特殊类型 jmp_buf, 这一数据类型是某种形式的数组,其中存放在调用
		longjmp 时能用来恢复栈状态的所有信息. 一般,env 变量是个全局变量,因此需
		从另一个函数中引用它
	3:C程序缺乏异常处理的语法,可使用非局部跳转处理C程序的异常
	4:goto 语句仅限于函数内部的跳转,而 longjmp 不限于


2:非局部跳转的注意点
	1:变量值问题
		int a = 10
		setjmp();
		a = 20;
		longjmp();
		// a 的值为多少
	2:gcc -O -o bin/longjmp_var src/longjmp_var.c
		经过编译优化后, auto/register 变量会发生改变
	3:易失变量 volatile
		1:保证是从原先的变量中取值,而不是从寄存器中取值. 因为当由中断程序时,中断
		  程序或在中断期间其他陈需可能修改了寄存器中的值
		2:中断服务程序或多线程编程(有共享变量)中可以使用 volatile(易失变量).
	1:视频 ppt 笔记
		1:全局变量,静态变量和 volatile(易失变量)不能恢复到原始值
		2:寄存器变量可以恢复到原始值
		3:自动变量的潜在问题: 优化编译后可能会恢复



示例
	process_jmp.c
	cal.c
	cal_my.c
	longjmp_var.c
