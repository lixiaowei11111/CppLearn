#include<iostream>

using namespace std;

int main3() {
	
	// 1. float 声明变量时, 最好在值后面添加 字母 f或者F
	float f1 = 3.14; // 被编译器默认识别为了 double
	float f2 = 3.14f;// 识别为 float
	double d1 = 3.14;
	// 2. float 和 double 默认只会显示出6位 有效数字
	float f3 = 3.1415926f;
	double d2 = 3.1415926;

	cout << "f3:"<< f3 << endl; // 打印结果为3.14159
	cout << "d2:"<< d2 << endl; // 打印结果为3.14159

	// 3. float 和 double 类型 变量的占用空间
	cout << "float占用的空间为" << sizeof(float) << "byte" << endl;
	cout << "double占用的空间为" << sizeof(double) << "byte" << endl;
	cout << "float类型变量 f3占用的空间为" << sizeof(f3) << "byte" << endl;
	cout << "double类型变量 d2占用的空间为" << sizeof(d2) << "byte" << endl;

	// 4. 科学计数法表示
	cout << 3e2 << endl;// 3 x 10^2         300
	cout << 3e-2 << endl;// 3 x 0.1 x 10^2  0.03
	system("pause");
	return 0;
}