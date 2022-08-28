#include<iostream>

using namespace std;

int main1() {

	// 1.指针的定义 指针就是一个 指向内存地址的变量
	int a = 1000;

	// 1.1 指针的定义
	int* p;

	// 1.2 指针 取址 赋值
	p = &a;
	cout << &a << endl; // &a代表 a的地址
	cout << p << endl; // 变量 p 存的就是a的值

	// 2. 指针的使用 指针的解引用
	//通过 * 操作指针变量 指向内存,  取出对应指针变量P的值(地址)对应的值
	cout << "* p" << *p << endl;//1000
	cout << "a" << a << endl;// 1000


	system("pause");
	return 0;
}