#include<iostream>
using namespace std; // 预编译 命名空间为 std里面的函数


// 1.定义一个返回局部变量地址的方法


int* func(int b) {// 形参数据也被编译器 存放在 栈区

	int a = 10;
	return &a;
}



int main2() {
	//1. 栈区, 由编译器自动分配,自动释放. 包括 局部变量 和 函数函数形参
	//2. 不要返回局部变量的地址,  编译器会将其自动释放

	int* p = func(1);
	cout << *p << endl;//10
	cout << *p << endl;// 不同编译器结果不同, 但编译器会给出警告


	return 0;
}