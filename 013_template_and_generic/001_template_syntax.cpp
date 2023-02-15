#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 不适用泛型编程,交换 整数和 浮点数

// 1. 交换整数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. 交换浮点数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

// 使用
void test01() {
	int a = 10, b = 20;
	swapInt(a, b);
	cout << "a:" << a << ";" << "b:"<< b << endl; // a : 20;b:10
	double c = 0.13, d = 0.99;
	swapDouble(c, d);
	cout << "c:" << c << ";" << "d:" << d << endl;//c:0.99;d:0.13
}
// 使用上面两个函数定义显得代码过于臃肿,不利于维护, 利用cpp 泛型编程的思想 类似于typescript中的泛型
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test02() {
	// 使用泛型定义的函数的两种方法

	// 1. 编译器自动类型推导
	int a = 200, b = 88;
	mySwap(a, b);
	cout << "a:" << a << ";" << "b:" << b << endl; //a : 88; b:200

	// 2. 手动标明指定类型
	double c = 3.33, d = 9.9999;
	mySwap<double>(c, d);
	cout << "c:" << c << ";" << "d:" << d << endl;// c : 9.9999; d:3.33
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
