#include <iostream>

using namespace std;

// ��������� ����  ���ܲ����� �ڳ�Ա����,ʹ�� ȫ�ֺ�����������
class Person {
public:
	int m_A;
	int m_B;
	Person() :m_A(10), m_B(20) {
		cout << "�޲ι��캯��������" << endl;
	}
};

// ȫ�ֺ����������������
ostream& operator<<(ostream& cout, Person& p) {
	cout << "p.m_A: " << p.m_A << endl;
	cout << "p.m_B: " << p.m_B << endl;
	// ��������, �Ա������ʽ����
	return cout;
}

void test01() {
	Person p;
	cout << p << "hello world" << endl;
	// ���� �൱��
	/*ostream& out= cout << p;
	out << "hello world" << endl;*/
}
int main() {
	test01();
	system("pause");
	return 0;
}
