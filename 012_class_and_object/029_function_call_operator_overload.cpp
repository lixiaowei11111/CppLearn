#include <iostream>

using std::cout;
using std::endl;
using std::string;

// �������÷��� () ��������, �������� ������ STL
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
	myStr("����һ������ () ����������string�Ĳ���");
	// ��������Ĵ�����ʽ
	MyString()("MyString() ������һ����������");
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
