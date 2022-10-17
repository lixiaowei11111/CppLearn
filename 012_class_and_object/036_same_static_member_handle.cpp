#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 同名静态属性和静态函数的访问
//静态成员属性
//1.在编译阶段分配内存
//2.类内声明, 类外初始化
//静态成员函数  
//1.静态成员只能访问 静态变量, 因为静态成员的数据只存在一份, 而访问 
//2.普通变量时,该普通变量是根据类定义的实例来变化的,有多个地址上存在了 该普通变量,肯定是不允许访问和修改的

class Base {
public:
	static int m_A;
	static void func1() {
		cout << "Base static void func1()" << endl;
	};
	static void func1(int a) {
		cout << "Base static void func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	static int m_A;
	static void func1() {
		cout << "Son static void func1()" << endl;
	}
};
int Base::m_A = 100;
int Son::m_A = 200;

void test01() {
	Son s;
	cout << s.m_A << endl;// 200
	cout << s.Base::m_A << endl;// 100
	cout << Son::m_A << endl;// 200
	cout << Son::Base::m_A << endl;//100
	Son::func1();// Son static void func1()
	Son::Base::func1();//Base static void func1()
	Son::Base::func1(100);//Base static void func1(int a)
}

int main() {
	test01();
	system("pause");
	return 0;
}
