#include<iostream>


using std::cout;
using std::endl;


// 声明函数;
void func();
void func();// 重复声明

void func(int a);

void func(int a, int);

void func(float a);

void func(double a, int b);



int main3() {
	func();
	func(1);
	func(1, 2);
	func(2.14f);
	func(3.14, 2);

	system("pause");
	return 0;
}


//定义函数

void func(){
	cout << "param 为空" << endl;
}

void func(int a) {
	cout << "参数为int a" << endl;
}

void func(int a, int) {
	cout << "参数为int a, int" << endl;
}

void func(float a) {
	cout << "参数为float a" << endl;
}

void func(double a, int b) {
	cout << "参数为double a, int b" << endl;
}