#include<iostream>
using namespace std; // Ԥ���� �����ռ�Ϊ std����ĺ���


// 1.����һ�����ؾֲ�������ַ�ķ���
int* func() {
	// new �ؼ����� ���� �п��ٵ�ַ, �����е��ڴ�����ɳ���Ա���ֶ��ͷŷ���
	int* p = new int(10);// new �ؼ�����C++ �б����صľ��� ��ַ, ʹ��ָ��������
	return p;
}



int main3() {
	int* p = func();
	cout << *p << endl;//10
	cout << *p << endl;//10


	return 0;
}