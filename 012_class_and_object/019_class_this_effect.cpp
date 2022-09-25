#include <iostream>

using std::cout;
using std::endl;
using std::string;

// this指针的作用
//1. 用于区分同名的形参和成员变量
//2.可以返回return *this(可用于作为链式调用)

class Person {
public:
	int age;
	Person(int age) {
		this->age = age;
		cout << "有参构造被调用" << endl;
	};
	// 链式调用
	Person& addAge(int age) {
		this->age += age;
		return *this;
	}
	// 一定要返回引用, 类似于 return Person& p2=*this, 如果不反悔引用则等同于返回的是 return Person p1=*this, 相当于使用隐式转换法去新建了一个Person实例返回,age的初始值永远都是构造函数中的10
};

void test01() {
	//Person p1;//error 当class中有有参构造时,编译器不再提供默认构造,所以会报错
	Person p1(10);
	cout << p1.age << endl;//10

	Person p2(10);
	cout << p2.age << endl;//10

	p2.addAge(10).addAge(10).addAge(20);
	cout << p2.age << endl;//50
}

int main() {
	test01();
	system("pause");
	return 0;
}
