#include<iostream>

using std::cout;
using std::endl;


// 
void showValue(const int& ref) {
	// const修饰 引用变量时, 引用变量指向的值也不能再被修改
	// ref = 20;// vs2022报错, 表达式必须是可修改的左值
	cout << ref << endl;
}


int main() {

	// 正常情况下, 声明引用必须初始化,分配一个合理的引用地址
	//直接复制==赋值是违法的
	//int& ref = 200;

	//const修饰 引用
	const int& ref = 200;
	//相当于 int temp = 10;const int& ref = temp;
	//ref = 20;// const修饰后,变为只读常量
	int a = 20;
	showValue(a);

	system("pause");
	return 0;
}