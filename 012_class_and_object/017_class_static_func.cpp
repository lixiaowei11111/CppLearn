#include <iostream>

using std::cout;
using std::endl;
using std::string;

//所有成员共享同一个函数
//静态成员函数只能访问静态成员变量
class Person {
public:
	static int a;
	int b;
	static void func01(int b) {
		a = b;
		// 静态成员只能访问 静态变量, 因为静态成员的数据只存在一份, 而访问 普通变量时,该普通变量是根据类定义的实例来变化的,有多个地址上存在了 该普通变量,肯定是不允许访问和修改的
		//cout << b << endl;//静态成员函数 不允许读取普通变量
		//b = 20;//静态成员函数 不允许修改普通变量
	}
private:
	static void func02();// 静态成员和普通成员一样,收到权限修饰符的影响
};

int Person::a = 20;
//int Person::func02(){}// 不能访问 private

void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p;
	cout << "p.a: " << p.a << endl;//20 通过 实力访问
	cout << "Peson::a :" << Person::a << endl;//20 通过类访问

	// 实例访问 static memeber function
	p.func01(30);
	cout << "p.a: " << p.a << endl;//30 通过 实力访问
	cout << "Peson::a :" << Person::a << endl;//30 通过类访问

	// 类 本身访问 static member function
	Person::func01(100);
	cout << "p.a: " << p.a << endl;//100 通过 实力访问
	cout << "Peson::a :" << Person::a << endl;//100 通过类访问


}