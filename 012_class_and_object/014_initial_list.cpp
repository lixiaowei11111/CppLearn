#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
public:
	int m_A;
	int m_B;
	int m_C;
	// ��ͳ�ĳ�ʼ����ֵ
	/*Person(int a, int b,int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	};*/
	// ʹ�ó�ʼ���б���г�ʼ����ֵ
	/*Person() :m_A(10), m_B(20), m_C(30) {

	};*/
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {

	};
};


void test01();
int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p1(10, 20, 30);
	//Person p1;
	cout << "m_A: " << p1.m_A << endl;
	cout << "m_B: " << p1.m_B << endl;
	cout << "m_C: " << p1.m_C << endl;

}