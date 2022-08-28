#include<iostream>

using namespace std;

int main5() {
	int a1 = 10;
	int c1 = 20;

	// 1. 常量指针   指向常量的指针
	// 指针变量p的值(即 &a)可以修改, 指针变量p的值指向的值,是一个不能被修改的常量
	const int * p1 = &a1;
	//* p1 = 20;// 编译器直接报错, 表达式必须是一个可修改的左值
	p1 = &c1;// 指针变量的值修改为c1了
	cout << "现在的a1的值是:" << a1 << "\n" << "现在指针p1的值(地址:)" << p1 << "\n" << "现在指针变量p1的值(地址)指向的值为:" << *p1 << endl;

	// 2.指针常量  指针的值(即指针地址,指针指向)为 一个常量
	// 指针变量p2的值(即 &a2)不能修改, 指针变量p2的值指向的值,不能被修改
	int a2 = 10;
	int c2 = 20;
	int * const p2 = &a2;
	* p2 = 20;// 可以修改 指针变量的值指向的值 即 现在 a2是20
	//p2 = &c;//编译器直接报错, 表达式必须是一个可修改的左值
	cout << "现在的a2的值是:" << a2 << "\n" << "现在指针p2的值(地址:)" << p2 << "\n" << "现在指针变量p2的值(地址)指向的值为:" << *p2 << endl;

	// 3. const 即修饰指针,又修饰常量
	// 指针变量p的值(即 &a)不可以修改, 指针变量p的值指向的值,也不能被修改
	int a3 = 10;
	int c3 = 20;
	const int * const p3 = &a3;
	//* p3 = 20;//编译器直接报错, 表达式必须是一个可修改的左值
	//p3 = &c3;//编译器直接报错, 表达式必须是一个可修改的左值

	system("pause");
	return 0;
}