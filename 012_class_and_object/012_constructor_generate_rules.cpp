#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
public:
	int m_Height = 0;
	// Ĭ�Ϲ��� default constructor
	Person() {
		cout << "������Ĭ�Ϲ���" << endl;
	};
	// �вι��� ���캯��������
	Person(int h) {
		m_Height = h;
		cout << "�������вι���" << endl;
	};
	// �������� ���캯������
	Person(const Person& p) {
		m_Height = p.m_Height;
		cout << "�����˿�������" << endl;
	};
	//�������� destructor
	~Person() {
		cout << "��������������" << endl;
	};
};

//1.����û��ж����вι��캯��,c++ �����ṩĬ�ϵ��޲ι���,���ǻ��ṩĬ�Ͽ�������
void test01(); //��������
//2.����û����忽�����캯��,c++�������ṩ�������캯��
void test02();
int main() {
	test01();


	system("pause");
	return 0;
}

void test01() {
	//Person p1;//�﷨����!  ����û����忽�����캯��,�������������ṩĬ�Ϲ���
	Person p1(20);// �������вι���
	Person p2(p1);// �����˿�������
	// ���ֻд���вι���, ������ ���Զ�ִ��һ��ֵ���ݵĿ�������
	cout << "p2ʵ����1m_Height:" << p2.m_Height << endl;
}

void test02() {
	//Person p1;//�﷨����!  ����û����忽�����캯��,�������������ṩĬ�Ϲ���
}