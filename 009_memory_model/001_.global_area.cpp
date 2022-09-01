#include<iostream>
#include<string>

using std::cout;
using std::endl;

// 1.定义全局变量
int g_a = 123;
int g_b = 456;

//4.定义静态全局变量
static int s_g_a = 123;
static int s_g_b = 456;

//6. 定义和初始化 全局常量
const int c_g_a = 123;
const int c_g_b = 456;

int main1() {
	//2. 定义局部变量
	int l_a = 123;
	int l_b = 345;
	cout << "全局常量 g_a的地址为:  " << (int)&g_a << endl;
	cout << "全局常量 g_b的地址为:  " << (int)&g_b << endl;
	cout << "局部常量 l_a的地址为:  " << (int)&l_a << endl;
	cout << "局部常量 l_b的地址为:  " << (int)&l_b << endl;

	//3. 定义静态局部变量, 使用 static
	static int s_l_a = 123;
	static int s_l_b = 456;
	cout << "static全局常量 c_g_a的地址为:  " << (int)&s_g_a << endl;
	cout << "static全局常量 c_g_b的地址为:  " << (int)&s_g_b << endl;
	cout << "static局部常量 s_l_a的地址为:  " << (int)&s_l_a << endl;
	cout << "static局部常量 s_l_b的地址为:  " << (int)&s_l_b << endl;

	//4.const 修饰 局部变量
	const int c_l_a = 123;
	const int c_l_b = 456;
	cout << "全局常量 c_g_a的地址为:  " << (int)&c_g_a << endl;
	cout << "全局常量 c_g_b的地址为:  " << (int)&c_g_b << endl;
	cout << "局部常量 c_l_a的地址为:  " << (int)&c_l_a << endl;
	cout << "局部常量 c_l_b的地址为:  " << (int)&c_l_b << endl;
	//5.字符串常量
	cout << "字符串常量的地址为" << (int)&"hello_world" << endl;


	system("pause");
	return 0;
}