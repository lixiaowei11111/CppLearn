#include<iostream>


using std::cout;
using std::endl;

//1. ��ĳ��������Ĭ�ϲ���ʱ, �ò������ұߵĲ���Ҳ������Ĭ�ϲ���

//int addFunc(int a=10,int b,int c=2);// ���������� Ĭ��ʵ�β����βν�β���б�
int addFunc2(int a = 1, int b = 2, int c = 4);

// 2. Ĭ�ϲ��������ض���(���ں�����������,���ں�������)
int sumFunc1(int a = 10,int b = 10);

int sumFunc(int a = 10, int b = 10) {
	return a + b;
}



int main1() {

	cout << sumFunc(10, 10) << endl;// ���� �ض���Ĭ�ϲ��� :����1,����2

	system("pause");
	return 0;
}
