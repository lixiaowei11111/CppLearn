#include<iostream>
using namespace std;



// #define 定义的宏常量
// const 用于 修饰不可变的变量
#define day 7

int main() {
	const int a = 12;
	cout << "#define 定义的变量为" << day << endl;
	cout << "const 定义的变量为" << a << endl;
	system("pause");
	return 0;
}