#include<iostream>
using namespace std;



int main7() {
	// 1. C语言风格字符串, 把字符串 看成一个 字符数组
	/*
	*注意事项
	* 1.必须使用 双引号
	* 2. 定时时同样使用char 关键字, 但是变量后面跟一个 []表示数组
	*/
	char ch[] = "abc";
	cout << "C语言风格字符串" << ch << endl;

	//2. C++ 风格字符串, 定义为string即可
	// 可能需要引入头文件 #include<string>
	string ch2 = "abc";
	cout << "C++ 风格的字符串" << ch2 << endl;

	system("pause");
	return 0;

}