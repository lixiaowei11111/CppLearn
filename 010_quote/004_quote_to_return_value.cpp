#include<iostream>

using std::cout;
using std::endl;


// 定义一个全局变量
double vals[] = { 1.23,3.14,6.28 };

// 声明一个返回引用的函数
double& test01(int i);


// 不能返回一个局部变量的引用
int& test02() {
	int i = 10;
	return i;
}
int main4() {

	//改变值之前的全局变量
	for (size_t i = 0; i < 3; i++)
	{
		cout << "vals[" << i << "]: " << vals[i] << endl;
	}
	// 通过返回函数的引用值改变
	test01(2) = 3.25;
	test01(0) = 3.25;

	//改变值之后的数组
	for (size_t i = 0; i < 3; i++)
	{
		cout << "vals[" << i << "]: " << vals[i] << endl;
	}
	cout<<test02()<<endl;// 报错

	system("pause");
	return 0;
}

// 定义一个 返回引用的变量
double& test01(int i) {
	double& ref = vals[i];// 数组中 指定位置 i的值 被地址引用被返回
	return ref;
}
