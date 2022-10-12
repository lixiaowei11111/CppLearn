#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// ����(�Լ������ ��Ϊ ǰ�� ����,���������, ����� i++ �� ++i������)
class MyInteger {

	friend ostream& operator<<(ostream& cout, MyInteger myInteger);
public:
	// Ĭ�Ϲ��캯��
	MyInteger() {
		m_Int = 10;
	};
	// ǰ����������� ��++ �ٷ���
	MyInteger& operator++() {
		++m_Int;
		return *this;
	}
	// ������������� �ȷ��ص�ǰ����,��ִ��++ ����
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Int++;
		return temp;
	}
private:
	int m_Int;
};

// ��д ����<< �����,�������MyInterger ʵ��
ostream& operator<<(ostream& cout,MyInteger myInteger) {
	cout << myInteger.m_Int << endl;
	return cout;
}

// ���� ++
void test01() {
	MyInteger m;
	/*cout << ++m << endl;*/
	cout << m++ << endl;
	cout << m << endl;
}
//ǰ�� ++
void test02() {
	MyInteger m;
	cout << ++(++m) << endl;
	cout << m << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
