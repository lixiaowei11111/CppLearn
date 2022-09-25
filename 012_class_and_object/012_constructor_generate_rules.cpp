#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
public:
	int m_Height = 0;
	// 默认构造 default constructor
	Person() {
		cout << "调用了默认构造" << endl;
	};
	// 有参构造 构造函数的重载
	Person(int h) {
		m_Height = h;
		cout << "调用了有参构造" << endl;
	};
	// 拷贝构造 构造函数重载
	Person(const Person& p) {
		m_Height = p.m_Height;
		cout << "调用了拷贝构造" << endl;
	};
	//析构函数 destructor
	~Person() {
		cout << "调用了析构函数" << endl;
	};
};

//1.如果用户有定义有参构造函数,c++ 不在提供默认的无参构造,但是会提供默认拷贝构造
void test01(); //函数声明
//2.如果用户定义拷贝构造函数,c++不会再提供其他构造函数
void test02();
int main() {
	test01();


	system("pause");
	return 0;
}

void test01() {
	//Person p1;//语法错误!  如果用户定义拷贝构造函数,编译器不会再提供默认构造
	Person p1(20);// 调用了有参构造
	Person p2(p1);// 调用了拷贝构造
	// 如果只写了有参构造, 编译器 会自动执行一个值传递的拷贝构造
	cout << "p2实例的1m_Height:" << p2.m_Height << endl;
}

void test02() {
	//Person p1;//语法错误!  如果用户定义拷贝构造函数,编译器不会再提供默认构造
}