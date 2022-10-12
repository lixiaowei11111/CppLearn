#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// �������������, ��Ϊ ǰ�õݼ��� ���õݼ�

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger m);
public:
	// Ĭ�Ϲ��캯��
	MyInteger() {
		m_Int=10;
	}
	/*ǰ�õݼ�,���������õ����
	MyInteger operator--() {
		m_Int--;
		return *this;
	}*/
	// ǰ�õݼ� ������ �ٷ��������Ľ��, Ҫ����ʽ���� ,ʹ������������ͬһ������,�����ǵ���class�ڲ��Ŀ������캯���½�һ��ʵ��
	MyInteger& operator--() {
		m_Int--;
		return *this;
	}
	// ���õݼ�
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Int--;
		return temp;
	}
private:
	int m_Int;
};

// ���� << �����
ostream& operator<<(ostream& cout, MyInteger m) {
	cout << m.m_Int << endl;
	return cout;
}

// 1. ǰ�õݼ�, �����������õ����
void test01() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 9
}
void test02() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 8
}

//2.���õݼ�
void test03() {
	MyInteger m;
	cout << m-- << endl;//10
	cout << m << endl;//9
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
