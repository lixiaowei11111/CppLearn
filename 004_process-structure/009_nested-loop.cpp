#include<iostream>

using namespace std;

int main() {
	// 1.打印1个 10*10的 矩阵*图
	for (int i = 0; i < 10; i++) {
		for (int c = 0; c < 10; c++) {
			cout << "*  ";
		}
		cout << "\n";
	}
	// 2.打印 99乘法表
	for (int i = 1; i < 10; i++) {
		for (int c = 1; c <= i; c++) {
			cout << i << "x" << c << "=" << i * c << "   ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}