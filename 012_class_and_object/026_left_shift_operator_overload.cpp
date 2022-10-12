#include <iostream>

using namespace std;

// 左移运算符 重载  可能不适用 于成员函数,使用 全局函数进行重载
class Person {
public:
	int m_A;
	int m_B;
	Person() :m_A(10), m_B(20) {
		cout << "无参构造函数被调用" << endl;
	}
};

// 全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p) {
	cout << "p.m_A: " << p.m_A << endl;
	cout << "p.m_B: " << p.m_B << endl;
	// 返回引用, 以便进行链式调用
	return cout;
}

void test01() {
	Person p;
	cout << p << "hello world" << endl;
	// 以上 相当于
	/*ostream& out= cout << p;
	out << "hello world" << endl;*/
}
int main() {
	test01();
	system("pause");
	return 0;
}
