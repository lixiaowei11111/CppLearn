#include<iostream>


using std::cout;
using std::endl;


// ��������ʱ ,ѡ������ ��Ϊ����ʱ��ע������

void func1(int& a);

void func1(const int& a);

//������Ĭ�ϲ���ʱ�Ķ�����

void func2(int a);

void func2(int a, int b = 10);

int main() {
	int a = 10;
	func1(a);// �൱�� int& a=a; �Ϸ�


	func1(10);// �൱�� const int& a=10; �Ϸ���,���ǵ�һ������func(int&a), int& a=10; ���Ϸ�

	//func2(10);// ����������,�ж�����غ�����֮ƥ��

	func2(10, 12); // func2(int a,int b = 10)

	system("pause");
	return 0;
}

void func1(int& a) {
	cout << "func(int& a)" << endl;
}

void func1(const int& a) {
	cout << "func(const int& a)" << endl;
}

void func2(int a) {
	cout << "func2(int a)" << endl;
}

void func2(int a, int b) {
	cout << "func2(int a,int b = 10)" << endl;
}