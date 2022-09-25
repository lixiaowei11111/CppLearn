#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 空指针在调用 class中的方法时,不能用this来操作属性,因为空指针上没有该属性
class Person {
public:
	int m_Age;
	static int m_Height;
	void showClassName() {
		cout << "this is a Person class" << endl;
	}
	void showAge() {
		// 空指针上 this指针指向是没有m_Age属性成员的;
		cout << this->m_Age << endl;
	}
	void showHeight() {
		// 空指针上 this指针指向是没有m_Age属性成员的;
		cout << this->m_Height << endl;
	}
};

void test01() {
	Person* p = NULL;
	p->showClassName();
	//p->showAge();//Error 空指针上 this指针指向是没有m_Age属性成员的;
	//p->showHeight();
}

int main() {
	test01();
	system("pause");
	return 0;
}
