void data_sort(int data[], int n, void(*p)(int*, int), void(*out)(int*, int))
{
	/* 通过函数指针 p 去调用不同的实现排序算法的回调函数 */
	p(data, n);
	/* 通过函数指针 out 去调用输出数组元素的回调函数 */
	out(data, n);
}
