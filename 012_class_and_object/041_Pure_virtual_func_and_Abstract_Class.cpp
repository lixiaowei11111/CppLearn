#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
public:
	// 纯虚函数
	// class 中只要有一个纯虚函数, 这个类就被称为 抽象类
	// 抽象类的特点:
	// 1.无法实例化对象
	// 2. 抽象类的子类必须重写 父类中的 纯虚函数, 否则也会被视为一个 抽象类,同样不能被实例化
	virtual void speak() = 0;

};

class Son :public Base {

};

class Son2 :public Base {
public:
	void speak() {
		cout << "重写纯虚函数" << endl;
	}
};

void test01() {
	//Base base;// 拥有 纯虚函数的抽象类 不能被实例化
	// Son son;// 继承抽象类,但是没有重写基类中的纯虚函数的派生类, 同样无法实例化
	Son2 *s=new Son2;
	s->speak();
}

int main() {
	test01();
	system("pause");
	return 0;
}
