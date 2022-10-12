#include <iostream>

using std::cout;
using std::endl;
using std::string;
// �� + ���������������
// 1. class ��Ա���� ���������
class Home {
public:
	int m_A;
	int m_B;
	Home() :m_A(10), m_B(10) {
		cout << "Home �޲ι��챻����, �޲ι��촴��δ������ʱ��������ʹ��, �������������ɻ��Զ�����" << endl;
	}
	Home(int a, int b) :m_A(a), m_B(b) {
		cout << "Home �вι��챻����, �޲ι��촴��δ������ʱ��������ʹ��, �������������ɻ��Զ�����" << endl;
	}
	Home operator+(const Home& h) {
		Home home;
		home.m_A = h.m_A + m_A;
		home.m_B = h.m_B + m_B;
		return home;
	}
};


// 1.�������ؼӺ�������ĳ�Ա����
void test01() {
	Home h1;
	Home h2;
	Home h3 = h1 + h2;
	// �൱��,  ����һ���﷨��
	//Home h3 = h1.operator+(h2)
	cout << h3.m_A << "    " << h3.m_B << endl;// 20  20
}

// 2.����ȫ�ֺ��� �������������
Home operator-(const Home& h1, const Home& h2) {
	Home home;
	home.m_A = h1.m_A - h2.m_A;
	home.m_B = h1.m_B - h2.m_B;
	return home;
}

void test02() {
	Home h1(30, 30);
	Home h2(30, 30);
	Home h3 = h1 - h2;
	//�൱��
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// 0  0
}

// 3.���Ѿ����ع��� operaotr- �����ٴ�����
Home operator-(const Home& h1, int a) {
	Home home;
	home.m_A = h1.m_A - a;
	home.m_B = h1.m_B - a;
	return home;
}
void test03() {
	Home h1(30, 30);
	Home h3 = h1 -40 ;
	//�൱��
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// -10  -10
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
