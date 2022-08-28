#include<iostream>

using namespace std;

int main5() {
	// 1. 定义字符型 变量
	char ch = 'a';
	char ch4 = 'A';
	cout << ch << endl;
	//2. 整型占用空间大小
	cout << "char 类型占用的空间大小为" << sizeof(ch) << "byte"<<endl;
	// 3. 整型常见错误
	//char ch2 = "a"; 报错不能编译
	char ch3 = 'abc';
	// 4. 强制类型转化, 字母 对应的ASCII编码
	cout << int(ch) << endl; // a ==> 97
	cout << int(ch4) << endl;// A ==> 65
	system("pause");
	return 0;
}