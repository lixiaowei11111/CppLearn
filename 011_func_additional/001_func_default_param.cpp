#include<iostream>


using std::cout;
using std::endl;

//1. 当某个参数有默认参数时, 该参数的右边的参数也必须有默认参数

//int addFunc(int a=10,int b,int c=2);// 编译器报错 默认实参不在形参结尾的列表
int addFunc2(int a = 1, int b = 2, int c = 4);

// 2. 默认参数不能重定义(即在函数声明定义,又在函数定义)
int sumFunc1(int a = 10,int b = 10);

int sumFunc(int a = 10, int b = 10) {
	return a + b;
}



int main1() {

	cout << sumFunc(10, 10) << endl;// 报错 重定义默认参数 :参数1,参数2

	system("pause");
	return 0;
}
