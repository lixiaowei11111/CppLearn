#include<iostream>

using namespace std;

int main1() {

	// 1.ָ��Ķ��� ָ�����һ�� ָ���ڴ��ַ�ı���
	int a = 1000;

	// 1.1 ָ��Ķ���
	int* p;

	// 1.2 ָ�� ȡַ ��ֵ
	p = &a;
	cout << &a << endl; // &a���� a�ĵ�ַ
	cout << p << endl; // ���� p ��ľ���a��ֵ

	// 2. ָ���ʹ�� ָ��Ľ�����
	//ͨ�� * ����ָ����� ָ���ڴ�,  ȡ����Ӧָ�����P��ֵ(��ַ)��Ӧ��ֵ
	cout << "* p" << *p << endl;//1000
	cout << "a" << a << endl;// 1000


	system("pause");
	return 0;
}