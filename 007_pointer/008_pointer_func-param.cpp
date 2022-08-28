#include<iostream>

using namespace std;


// 1.先声明函数,再定义和使用函数
void swap(int* p1, int* p2);



int main8() {
	// 指针用作函数参数
	int a = 20;
	int b = 10;
	swap(&a, &b);// 这时函数不再是传值调用,而是指针调用
	cout << "a的值:" << a << "\n" << "b的值" << b << endl;// 10 20
	system("pause");
	return 0;
}

// 2.定义函数
void swap(int* p1, int* p2) {
	int temp = *p2;// 获取p1指针指向的值
	*p2 = *p1;
	*p1 = temp;

}