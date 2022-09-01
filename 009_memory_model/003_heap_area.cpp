#include<iostream>
using namespace std; // 预编译 命名空间为 std里面的函数


// 1.定义一个返回局部变量地址的方法
int* func() {
	// new 关键字在 堆区 中开辟地址, 堆区中的内存变量由程序员来手动释放分配
	int* p = new int(10);// new 关键字在C++ 中本身返回的就是 地址, 使用指针来接收
	return p;
}



int main3() {
	int* p = func();
	cout << *p << endl;//10
	cout << *p << endl;//10


	return 0;
}