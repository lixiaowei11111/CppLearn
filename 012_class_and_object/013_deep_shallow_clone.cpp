#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 1. class �е� �������캯��Ĭ��Ϊ ǳ����, ����new������ ������ַ���� ���
class Person {
public:
	int m_Height;
	int* m_age;// int ���͵�ָ�����
	Person(int h,int a) {
		m_Height = h;
		m_age = new int(a);
		cout << "�вι��캯���ĵ���" << endl;
	}
	Person(const Person& p) {
		m_Height = p.m_Height;
		//m_age = p.m_age;// ���������ṩ�ľ�������������ǳ����, ʹ�õı���������һ����ַ
		m_age = new int (*p.m_age);// ���¿���һ�����������ֵ
		cout << "�������캯���ĵ���" << endl;
	}
	~Person() {
		if (m_age != NULL) {
			delete m_age;// new ���ٵĿռ���Ҫ�ֶ��ͷ�
			m_age = NULL;// ��ֹҰָ��
		}
		cout << "destructor �ĵ���" << endl;
	}
};
void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p1(180, 20);
	cout << "p1�����:" << p1.m_Height << "\np1������:" << *p1.m_age << endl;
	Person p2(p1);
	cout << "p2�����:" << p2.m_Height << "\np2������:" << *p2.m_age << endl;
}
