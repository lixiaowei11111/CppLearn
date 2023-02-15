#include <iostream>

using std::cout;
using std::endl;
using std::string;

// �����÷��ͱ��,���� ������ ������

// 1. ��������
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//2. ����������
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

// ʹ��
void test01() {
	int a = 10, b = 20;
	swapInt(a, b);
	cout << "a:" << a << ";" << "b:"<< b << endl; // a : 20;b:10
	double c = 0.13, d = 0.99;
	swapDouble(c, d);
	cout << "c:" << c << ";" << "d:" << d << endl;//c:0.99;d:0.13
}
// ʹ�������������������Եô������ӷ��,������ά��, ����cpp ���ͱ�̵�˼�� ������typescript�еķ���
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test02() {
	// ʹ�÷��Ͷ���ĺ��������ַ���

	// 1. �������Զ������Ƶ�
	int a = 200, b = 88;
	mySwap(a, b);
	cout << "a:" << a << ";" << "b:" << b << endl; //a : 88; b:200

	// 2. �ֶ�����ָ������
	double c = 3.33, d = 9.9999;
	mySwap<double>(c, d);
	cout << "c:" << c << ";" << "d:" << d << endl;// c : 9.9999; d:3.33
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
