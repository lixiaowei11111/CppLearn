#include<iostream>

using std::cout;
using std::endl;


// ����������,�Զ�ת��Ϊ ָ�볣�� int* const ref=&a;
void func(int& ref) {
	ref = 100;// ref������ , ���н����ò��� *ref = 100
}


int main5() {
	int a = 10;


	// �Զ�ת��Ϊָ�볣��(ָ��ָ�򲻱�) int* const ref = &a;
	int& ref = a;

	ref = 20;// �ڲ�����ref ������, �Զ�ת��Ϊ *ref = 20;

	cout << a << endl;//20
	cout << ref << endl;//20

	system("pause");
	return 0;
}