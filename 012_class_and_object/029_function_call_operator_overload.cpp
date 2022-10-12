#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 函数调用符号 () 进行重载, 这种重载 常用于 STL
class MyString {
public:
	void operator()(string str) {
		cout << str << endl;
	}
};
class MyAdd {
public:
	int operator()(int a,int b) {
		return a + b;
	}
};

void test01() {
	MyString myStr;
	myStr("这是一个重载 () 运算符传入的string的参数");
	// 匿名对象的创建方式
	MyString()("MyString() 创建了一个匿名对象");
}

void test02() {
	MyAdd myAdd;
	cout << myAdd(2, 3) << endl;//5
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
