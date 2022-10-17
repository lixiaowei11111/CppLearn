#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 一个子类可以同时继承多个父类
class Base1 {
public:
	int m_A;
	Base1() {
		m_A = 10;
	}
};

class Base2 {
public:
	int m_A;
	Base2() {
		m_A = 20;
	}
};

class Son :public Base1, public Base2 {
public:
	int m_B;
	int m_C;
};

void test01() {
	Son s;
	//cout << s.m_A << endl;//error Son::m_A不明确
	//继承的多个父类中有同名成员时,访问这些成员时需要加作用域进行区分
	cout << s.Base1::m_A << endl; // 10
	cout << s.Base2::m_A << endl; // 20
}
int main() {
	test01();
	system("pause");
	return 0;
}
