#include<iostream>

using std::cout;
using std::endl;

int main1() {
	// 1. ���� (���õĸ��������� JS����������,����ʹ�ö��������ֵָ��ͬһ����ַ,����ͨ��һ����������,����һ��������ȡ����ֵҲ��ı�,����Cpp�ж�ֵ����ͬ����Ч);
	int a = 10;

	// ʹ�ñ���b ����a��ֵ
	int& b = a;
	b = 20;
	cout << a << endl;// 20
	cout << b << endl;// 20

	cout << &b << endl;
	cout << &a << endl;// ��ַ��ͬ

	int c = 30;
	int* d = &c;
	*d = 40;
	cout << c << endl;// 40
	cout << *d << endl;//40



	system("pause");
	return 0;
}