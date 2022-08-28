#include<iostream>

using namespace std;

int main6() {
	// 1. 利用指针来访问一维数组中的每一个元素
	int arr[4] = { 1,2,3,4 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int * p = arr;// 指针指向数组的 首地址
	for (size_t i = 0; i < length; i++)
	{
		cout << "arr[" << i << "]的地址为" << (long long)p << endl;
		cout << "arr[" << i << "]的值为" <<  *p << endl;
		p++;// p=p+1 每次加 int类型的 byte
	}

	system("pause");
	return 0;
}