#include<iostream>

using namespace std;

int main7() {
	// 1. ָ��ָ���ָ��;
	int a = 10;
	int* p1 = &a;
	int** p2 = &p1;
	int*** p3 = &p2;

	cout << "a��ֵΪ" << a << endl; //10
	cout << "*p1��ֵΪ" << *p1 << endl;// 10
	cout << "*p2��ֵΪ" << *p2 << endl;// &p1 ��Ϊ ָ�����p1�ĵ�ַ
	cout << "**p2��ֵΪ" << **p2 << endl;//10
	cout << "***p3��ֵΪ" << ***p3 << endl;// 10 ָ���ָ���ָ��

	system("pause");
	return 0;
}