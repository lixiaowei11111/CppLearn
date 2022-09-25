#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 一个类的成员 可以是另外一个对象, 这个成员 是一个 对象成员
class Phone {
public:
	string m_Number;
	// 默认 constructor
	Phone() {
		cout << "class Phone默认构造函数" << endl;
	};
	// 有参 contructor
	Phone(string s) {
		m_Number = s;
		cout << " class Phone有参构造被调用" << endl;
	}
	// 拷贝 constructor
	Phone(const Phone& p) {
		m_Number = p.m_Number;
		cout << " class Phone拷贝构造被调用" << endl;
	}
	// destructor
	~Phone() {
		cout << " class Phone析构函数被调用" << endl;
	}
};

class Person {
public:
	
	// 默认 constructor
	Person(){
		cout << "class Person 默认构造函数" << endl;
	}
	// 有参 constructor
	Person(int a,string n):m_Age(a) ,m_Phone(n) {
		cout << "class Person 有参构造被调用" << endl;
	}
	// 拷贝 constructor
	Person(const Person& p) {
		m_Age = p.m_Age;
		m_Phone = p.m_Phone;
		cout << "class Person 拷贝构造被调用" << endl;
	}
	// destructor
	~Person() {
		cout << "class Person 析构函数被调用" << endl;
	}
	int m_Age;
	Phone m_Phone;

};
void test01();

int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p(20,"17673942507");
	// 构造时, 先执行 对象成员里的构造函数, 再执行类本身的构造函数
	//析构时, 先执行本身的析构函数,再执行 对象成员的构造函数
	cout << p.m_Age << p.m_Phone.m_Number << endl;
}
