#include<iostream>
using namespace std;

int main() {
	//1.算术运算符       cpp 中的四则运算
	int a = 1, b = 2;
	char c = 'a';
	double f = static_cast<double>(1) / 2;
	std::cout << 0.1+0.2 << a << b <<"\nchar:"<< c << "\nfloat:" << std::endl;
	std::cout << 30 - 1 << "\n" << 0.2 - 0.1 << std::endl;
	std::cout << 2 * 3 <<"\n" << 02. * 0.3 << std::endl;
	std::cout << f << "\n" << 0.1 / 0.2 << std::endl;
	std::cout << b%a << std::endl;
	int h = 2;
	int i = 2;
	std::cout << h++ << ++i << std::endl;
	int j = 3;
	int k = 3;
	std::cout << j-- << --k <<endl;

	//2.关系运算符
	int l = 10;
	short o = 11;
	string n = "ada";
	bool m = o == l;
	cout << m << endl;
	if (l==o) {
		cout << "o 等于 l" << endl;
	}
	if (l != 0) {
		cout << "o 不等于 l" << endl;
	}
	if (l > 0) {
		cout << "o 大于 l" << endl;
	}
	if (l < 0) {
		cout << "o 小于 l" << endl;
	}
	if (l >=0) {
		cout << "o 大于等于 l" << endl;
	}
	if (l <= 0) {
		cout << "o 小于等于 l" << endl;
	}

	// 3. 逻辑运算符
	int t = 1;
	bool q = false;
	string r = "string";

	cout << "!t:" << !t << endl;// 0
	cout << "!q:" << !q << endl;// 1
	//cout << "!r:" << !r << endl;// string类型不能被强转;
	int x = 1 && 2;
	int y = 1 || 2;
	int z = 10 || 0;
	cout << x<<y<<z<<endl;// 1 1 1

	// 4. 位运算符
	int aA = 60; //0011 1100
	int bB = 13; //0000 1101
	int cC = 0b1000;
	// 4.1 二进制 与 运算 &
	int dD = aA & bB;
	cout <<"二进制 与 运算 & :" << dD << endl;//12 0000 1100
	// 4.2 二进制 或 运算 |
	int eE = aA | bB;
	cout <<" 二进制 或 运算 | :" << eE << endl;//61  0011 1101
	// 4.3 二进制 非 运算 ~
	cout <<"二进制 非 运算 ~ :" << ~cC << endl;// -9 
	// 4.4 二进制 异或 运算 ^
	int fF = aA ^ bB;
	cout <<"二进制 异或 运算 ^ :" << fF << endl;// 49
	// 4.5 二进制左移运算符 << 将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）
	int gg = 0b1000 << 2;
	cout << "二进制左移运算符 << :" << gg << endl;//32 100000
	// 4.6 二进制右移运算符 >> 将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。
	int hh = 0b1000 >> 2;
	cout <<"二进制右移运算符 >> :" << hh << endl;//2 0010

	system("pause");
	return 0;
}