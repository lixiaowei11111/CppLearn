#include<iostream>

using std::cout;
using std::endl;

int main2() {
	
	// ����ע������;
	
	//1.���ñ����ʼ��
	int a = 20;

	//int& b;// ����ʼ�����ñ���ʱ, vs2022�ᱨ��,δ�ܳ�ʼ�����ر���

	// 2.���ñ����� ָ�� ���ܱ��ٴθı�
	int& b = a;
	int c = 30;

	int& d = c;
	b = d; // ���õ�ֵ �����ٴα���ֵ
	cout << a << endl;





	system("pause");
	return 0;
}