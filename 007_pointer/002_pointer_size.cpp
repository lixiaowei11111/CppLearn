#include<iostream>

using namespace std;

int main2() {
	cout << "sizeof(int *)=" << sizeof(int *) << endl;//8
	cout << "sizeof(short *)=" << sizeof(short *) << endl;//8
	cout << "sizeof(float *)=" << sizeof(float *) << endl;// 8
	cout << "sizeof(double *)=" << sizeof(double*) << endl;// 8

	// 64位操作系统下, 占用8个字节


	system("pause");
	return 0;
}