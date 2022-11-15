#include <iostream>

using std::cout;
using std::endl;
using std::string;
// 静态多态
// 函数重载 和 运算符重载
// 编译阶段确定函数地址 - 早绑定

//动态多态
// 派生类 和 虚函数
// 运行阶段确定函数地址 - 晚绑定


class Animal {
public:
	// 函数前加 virtual 加修饰符表示 虚函数
	virtual void speak() {
		cout << "Animal speak" << endl;
	}
};

class Cat:public Animal {
public:
	void speak() {
		cout << "Cat speak" << endl;
	}
};

class Dog:public Animal {
public:
	virtual void speak() {
		cout << "Dog speak" << endl;
	}
	// 派生类中的 虚函数修饰符可加可不加
};


void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	Cat c;
	Dog d;
	// Dog 和 Cat 类中的对于父类的 speak函数都进行了重写

	// 重载 : 函数参数或者返回值不同
	// 重写 : 函数参数和返回值 和原函数一样
	doSpeak(c);
	doSpeak(d);
}

int main() {
	test01();
	system("pause");
	return 0;
}
