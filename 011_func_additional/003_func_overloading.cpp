#include<iostream>


using std::cout;
using std::endl;


// ��������;
void func();
void func();// �ظ�����

void func(int a);

void func(int a, int);

void func(float a);

void func(double a, int b);



int main3() {
	func();
	func(1);
	func(1, 2);
	func(2.14f);
	func(3.14, 2);

	system("pause");
	return 0;
}


//���庯��

void func(){
	cout << "param Ϊ��" << endl;
}

void func(int a) {
	cout << "����Ϊint a" << endl;
}

void func(int a, int) {
	cout << "����Ϊint a, int" << endl;
}

void func(float a) {
	cout << "����Ϊfloat a" << endl;
}

void func(double a, int b) {
	cout << "����Ϊdouble a, int b" << endl;
}