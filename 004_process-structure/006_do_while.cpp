#include<iostream>

using namespace std;

int main6() {
	// 打印 0~9
	int a = 0;
	do
	{
		cout << "当前a的值为:" << a << endl;
		a = a + 1;
	} while (a<10);
	system("pause");
	return 0;
}