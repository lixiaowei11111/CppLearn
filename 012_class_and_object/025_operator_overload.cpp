#include <iostream>

using std::cout;
using std::endl;
using std::string;
// 对 + 号运算符进行重载
// 1. class 成员函数 运算符重载
class Home {
public:
	int m_A;
	int m_B;
	Home() :m_A(10), m_B(10) {
		cout << "Home 无参构造被调用, 无参构造创建未被声明时将不能再使用, 但拷贝构造依旧会自动调用" << endl;
	}
	Home(int a, int b) :m_A(a), m_B(b) {
		cout << "Home 有参构造被调用, 无参构造创建未被声明时将不能再使用, 但拷贝构造依旧会自动调用" << endl;
	}
	Home operator+(const Home& h) {
		Home home;
		home.m_A = h.m_A + m_A;
		home.m_B = h.m_B + m_B;
		return home;
	}
};


// 1.调用重载加号运算符的成员函数
void test01() {
	Home h1;
	Home h2;
	Home h3 = h1 + h2;
	// 相当于,  这是一种语法糖
	//Home h3 = h1.operator+(h2)
	cout << h3.m_A << "    " << h3.m_B << endl;// 20  20
}

// 2.调用全局函数 进行运算符重载
Home operator-(const Home& h1, const Home& h2) {
	Home home;
	home.m_A = h1.m_A - h2.m_A;
	home.m_B = h1.m_B - h2.m_B;
	return home;
}

void test02() {
	Home h1(30, 30);
	Home h2(30, 30);
	Home h3 = h1 - h2;
	//相当于
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// 0  0
}

// 3.对已经重载过的 operaotr- 进行再次重载
Home operator-(const Home& h1, int a) {
	Home home;
	home.m_A = h1.m_A - a;
	home.m_B = h1.m_B - a;
	return home;
}
void test03() {
	Home h1(30, 30);
	Home h3 = h1 -40 ;
	//相当于
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// -10  -10
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
