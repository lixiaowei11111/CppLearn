#include <iostream>

using std::cout;
using std::endl;
using std::string;
// �������к� ������ͬ��������, ʹ�� :: ���ʸ�������,����������������


class Base {
public:
	int m_A;
	Base() {
		m_A = 100;
	}
};

class Son :public Base {
public:
	int m_A;
	Son() {
		m_A = 200;
	}
};
class Son2 :public Base {
	int m_A;
public:
	Son2() {
		m_A = 10;
	}
};

class Son3 :public Base {
public:
	int m_A;
	Son3() {
		m_A = 20;
	}
};

class Son4 :public Son3 {
public:
	int m_A;
	Son4() {
		m_A = 40;
	}
};

void test01() {
	Son s;
	cout << s.m_A << endl;// 200
	cout << s.Base::m_A << endl;// 100
}

void test02() {
	Son2 s;
	//cout << s.m_A << endl;// ���ɷ���
	cout << s.Base::m_A << endl;//100
}
void test03() {
	Son4 s;
	cout << s.m_A << endl;// 40
	cout << s.Son3::m_A << endl;// 20
	cout << s.Son3::Base::m_A << endl;// 100
	cout << s.Base::m_A << endl;// 100 ����һ�ַ���һ��
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
