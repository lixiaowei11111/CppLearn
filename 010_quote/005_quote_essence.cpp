#include<iostream>

using std::cout;
using std::endl;


// 发现是引用,自动转换为 指针常量 int* const ref=&a;
void func(int& ref) {
	ref = 100;// ref是引用 , 进行解引用操作 *ref = 100
}


int main5() {
	int a = 10;


	// 自动转换为指针常量(指针指向不变) int* const ref = &a;
	int& ref = a;

	ref = 20;// 内部发现ref 是引用, 自动转换为 *ref = 20;

	cout << a << endl;//20
	cout << ref << endl;//20

	system("pause");
	return 0;
}