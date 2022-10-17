#include <iostream>

using std::cout;
using std::endl;
using std::string;
// 当父子类中有相同的 同名函数时

class Base {
public:
	void func1() {
		cout << "Base类 func1" << endl;
	}
	void func1(int a) {
		cout << "Base类 func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	void func1() {
		cout << "Son类 func1" << endl;
	}
	// 子类有同名重载函数时
	void func1(int a) {
		cout << "Son类 func1(int a)" << endl;
	}
};
void test01() {
	Son s;
	s.func1();// Son类 func1
	s.Base::func1();// Base类 func1
	// 运行重载函数
	s.func1(2);// Son类 func1(int a)
	s.Base::func1(100);//Base类 func1(int a)
}
int main() {
	test01();
	system("pause");
	return 0;
}
