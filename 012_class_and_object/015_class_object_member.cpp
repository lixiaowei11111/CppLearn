#include <iostream>

using std::cout;
using std::endl;
using std::string;

// һ����ĳ�Ա ����������һ������, �����Ա ��һ�� �����Ա
class Phone {
public:
	string m_Number;
	// Ĭ�� constructor
	Phone() {
		cout << "class PhoneĬ�Ϲ��캯��" << endl;
	};
	// �в� contructor
	Phone(string s) {
		m_Number = s;
		cout << " class Phone�вι��챻����" << endl;
	}
	// ���� constructor
	Phone(const Phone& p) {
		m_Number = p.m_Number;
		cout << " class Phone�������챻����" << endl;
	}
	// destructor
	~Phone() {
		cout << " class Phone��������������" << endl;
	}
};

class Person {
public:
	
	// Ĭ�� constructor
	Person(){
		cout << "class Person Ĭ�Ϲ��캯��" << endl;
	}
	// �в� constructor
	Person(int a,string n):m_Age(a) ,m_Phone(n) {
		cout << "class Person �вι��챻����" << endl;
	}
	// ���� constructor
	Person(const Person& p) {
		m_Age = p.m_Age;
		m_Phone = p.m_Phone;
		cout << "class Person �������챻����" << endl;
	}
	// destructor
	~Person() {
		cout << "class Person ��������������" << endl;
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
	// ����ʱ, ��ִ�� �����Ա��Ĺ��캯��, ��ִ���౾��Ĺ��캯��
	//����ʱ, ��ִ�б������������,��ִ�� �����Ա�Ĺ��캯��
	cout << p.m_Age << p.m_Phone.m_Number << endl;
}
