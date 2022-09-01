#include<iostream>

using std::cout;
using std::endl;

int main2() {
	
	// 引用注意事项;
	
	//1.引用必须初始化
	int a = 20;

	//int& b;// 不初始化引用变量时, vs2022会报错,未能初始化本地变量

	// 2.引用变量的 指向 不能被再次改变
	int& b = a;
	int c = 30;

	int& d = c;
	b = d; // 引用的值 可以再次被赋值
	cout << a << endl;





	system("pause");
	return 0;
}