#include <iostream>

using std::cout;
using std::endl;
using std::string;
// ��������������ͬ�� ͬ������ʱ

class Base {
public:
	void func1() {
		cout << "Base�� func1" << endl;
	}
	void func1(int a) {
		cout << "Base�� func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	void func1() {
		cout << "Son�� func1" << endl;
	}
	// ������ͬ�����غ���ʱ
	void func1(int a) {
		cout << "Son�� func1(int a)" << endl;
	}
};
void test01() {
	Son s;
	s.func1();// Son�� func1
	s.Base::func1();// Base�� func1
	// �������غ���
	s.func1(2);// Son�� func1(int a)
	s.Base::func1(100);//Base�� func1(int a)
}
int main() {
	test01();
	system("pause");
	return 0;
}
