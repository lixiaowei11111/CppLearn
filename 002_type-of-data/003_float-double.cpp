#include<iostream>

using namespace std;

int main3() {
	
	// 1. float ��������ʱ, �����ֵ������� ��ĸ f����F
	float f1 = 3.14; // ��������Ĭ��ʶ��Ϊ�� double
	float f2 = 3.14f;// ʶ��Ϊ float
	double d1 = 3.14;
	// 2. float �� double Ĭ��ֻ����ʾ��6λ ��Ч����
	float f3 = 3.1415926f;
	double d2 = 3.1415926;

	cout << "f3:"<< f3 << endl; // ��ӡ���Ϊ3.14159
	cout << "d2:"<< d2 << endl; // ��ӡ���Ϊ3.14159

	// 3. float �� double ���� ������ռ�ÿռ�
	cout << "floatռ�õĿռ�Ϊ" << sizeof(float) << "byte" << endl;
	cout << "doubleռ�õĿռ�Ϊ" << sizeof(double) << "byte" << endl;
	cout << "float���ͱ��� f3ռ�õĿռ�Ϊ" << sizeof(f3) << "byte" << endl;
	cout << "double���ͱ��� d2ռ�õĿռ�Ϊ" << sizeof(d2) << "byte" << endl;

	// 4. ��ѧ��������ʾ
	cout << 3e2 << endl;// 3 x 10^2         300
	cout << 3e-2 << endl;// 3 x 0.1 x 10^2  0.03
	system("pause");
	return 0;
}