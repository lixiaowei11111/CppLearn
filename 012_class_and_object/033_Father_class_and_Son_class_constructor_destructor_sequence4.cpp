#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Father {
public:
	Father() {
		cout << "���๹�캯��ִ��" << endl;
	}
	~Father() {
		cout << "������������ִ��" << endl;
	}
};

class Son :public Father {
public:
	Son() {
		cout << "���๹�캯����ִ��" << endl;
	}
	~Son() {
		cout << "��������������ִ��" << endl;
	}
};

void test01() {
	Father f;
}

void test02() {
	Son s;
	// ���๹�캯��ִ��
	// ���๹�캯����ִ��
	// ��������������ִ��
	// ������������ִ��

}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
