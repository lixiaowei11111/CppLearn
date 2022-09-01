#include<iostream>


using std::cout;
using std::endl;


// 函数重载时 ,选用引用 作为参数时的注意事项

void func1(int& a);

void func1(const int& a);

//函数有默认参数时的二义性

void func2(int a);

void func2(int a, int b = 10);

int main() {
	int a = 10;
	func1(a);// 相当于 int& a=a; 合法


	func1(10);// 相当于 const int& a=10; 合法的,但是第一个函数func(int&a), int& a=10; 不合法

	//func2(10);// 编译器报错,有多个重载函数与之匹配

	func2(10, 12); // func2(int a,int b = 10)

	system("pause");
	return 0;
}

void func1(int& a) {
	cout << "func(int& a)" << endl;
}

void func1(const int& a) {
	cout << "func(const int& a)" << endl;
}

void func2(int a) {
	cout << "func2(int a)" << endl;
}

void func2(int a, int b) {
	cout << "func2(int a,int b = 10)" << endl;
}