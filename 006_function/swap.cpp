// 引用本地目录的头文件时, 使用双引号
#include "swap.h"



void swap(int num1, int param2) {
	int temp = param2;
	param2 = num1;
	num1 = temp;
	cout << "第一个参数的值被调换后为" << num1 << "\n" << "第二个参数的值被调换为:" << param2 << endl;
}