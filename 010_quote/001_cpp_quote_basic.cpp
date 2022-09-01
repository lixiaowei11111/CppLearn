#include<iostream>

using std::cout;
using std::endl;

int main1() {
	// 1. 引用 (引用的概念类似于 JS的引用类型,可以使得多个变量的值指向同一个地址,随意通过一个变量更改,另外一个变量获取到的值也会改变,不过Cpp中对值类型同样生效);
	int a = 10;

	// 使得变量b 引用a的值
	int& b = a;
	b = 20;
	cout << a << endl;// 20
	cout << b << endl;// 20

	cout << &b << endl;
	cout << &a << endl;// 地址相同

	int c = 30;
	int* d = &c;
	*d = 40;
	cout << c << endl;// 40
	cout << *d << endl;//40



	system("pause");
	return 0;
}