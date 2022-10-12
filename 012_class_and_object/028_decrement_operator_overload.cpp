#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// 递增运算符重载, 分为 前置递减和 后置递减

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger m);
public:
	// 默认构造函数
	MyInteger() {
		m_Int=10;
	}
	/*前置递减,不返回引用的情况
	MyInteger operator--() {
		m_Int--;
		return *this;
	}*/
	// 前置递减 先运算 再返回运算后的结果, 要想链式调用 ,使用引用来操作同一个对象,而不是调用class内部的拷贝构造函数新建一个实例
	MyInteger& operator--() {
		m_Int--;
		return *this;
	}
	// 后置递减
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Int--;
		return temp;
	}
private:
	int m_Int;
};

// 重载 << 运算符
ostream& operator<<(ostream& cout, MyInteger m) {
	cout << m.m_Int << endl;
	return cout;
}

// 1. 前置递减, 但不返回引用的情况
void test01() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 9
}
void test02() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 8
}

//2.后置递减
void test03() {
	MyInteger m;
	cout << m-- << endl;//10
	cout << m << endl;//9
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
