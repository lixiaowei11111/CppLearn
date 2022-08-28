#include<iostream>

using namespace std;

int main4(){
	// 野指针
	// 在程序中, 尽量避免 野指针
	// (int *)0x1100 将该16进制数字强转为 指针类型的值
	int* p = (int*)0x1100;// 引发了异常,读取访问权限冲突
	cout << *p << endl;

	system("pause");
	return 0;
}