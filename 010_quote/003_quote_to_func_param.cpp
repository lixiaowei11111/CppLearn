#include<iostream>

using std::cout;
using std::endl;


// 声明一个函数参数
void test01(int& param, int* param2);
int main3() {
	// 引用做函数返回值
	int a = 100;
	test01(a, &a);
	cout << a << endl;//20
	system("pause");
	return 0;
}

void test01(int& param,int* param2) {
	param = 20;
	cout << param << endl; //20
	cout << *param2 << endl;//20
};