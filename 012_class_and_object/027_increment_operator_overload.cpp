#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

// 自增(自减运算符 分为 前置 自增,与后置自增, 搞清楚 i++ 与 ++i的区别)
class MyInteger {

	friend ostream& operator<<(ostream& cout, MyInteger myInteger);
public:
	// 默认构造函数
	MyInteger() {
		m_Int = 10;
	};
	// 前置自增运算符 先++ 再返回
	MyInteger& operator++() {
		++m_Int;
		return *this;
	}
	// 后置自增运算符 先返回当前的数,再执行++ 操作
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Int++;
		return temp;
	}
private:
	int m_Int;
};

// 重写 左移<< 运算符,用于输出MyInterger 实例
ostream& operator<<(ostream& cout,MyInteger myInteger) {
	cout << myInteger.m_Int << endl;
	return cout;
}

// 后置 ++
void test01() {
	MyInteger m;
	/*cout << ++m << endl;*/
	cout << m++ << endl;
	cout << m << endl;
}
//前置 ++
void test02() {
	MyInteger m;
	cout << ++(++m) << endl;
	cout << m << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
