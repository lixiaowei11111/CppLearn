#include<iostream>

using namespace std;

int main7() {
	// 1. 指向指针的指针;
	int a = 10;
	int* p1 = &a;
	int** p2 = &p1;
	int*** p3 = &p2;

	cout << "a的值为" << a << endl; //10
	cout << "*p1的值为" << *p1 << endl;// 10
	cout << "*p2的值为" << *p2 << endl;// &p1 即为 指针变量p1的地址
	cout << "**p2的值为" << **p2 << endl;//10
	cout << "***p3的值为" << ***p3 << endl;// 10 指针的指针的指针

	system("pause");
	return 0;
}