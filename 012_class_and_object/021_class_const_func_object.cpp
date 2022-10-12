#include <iostream>

using std::cout;
using std::endl;
using std::string;

//常函数
class Person {
public:
	int m_Age;
	mutable int m_Height;// mutable 修饰成员属性,来指明这是一个可修改的成员属性, 不受到常函数的影响
	// this 指针的本质是一个指针常量,指针的指向是不可以改变的,永远指向 实例对象
	// 但是 this指向的值是可以变的
	void setAge(int age) {
		this->m_Age = age;
	}
	// 通过const加载函数参数后面来修饰this,  将this指针变成一个 常量指针常量, 使得this指向(实例)里面的值也不可被修改
	void setHeight(int h)const {
		//this->m_Age = 20;// error要想修改 成员属性, 必须加上mutable
		this->m_Height = h;//Error, 要想修改 成员属性, 必须加上mutable
	}
};
// 常对象, 本质还是和thi指针一回事, 因为this指针指向的就是常对象
void test01() {
	const Person p;// 1. 使用const 来修饰一个常对象,  常对象成员属性不能更改, 除非该成员属性前有mutable修饰符号
	p.setHeight(20);// 常对象只能调用常函数
	//p.setAge(20);//常对象不能调用普通函数,因为普通函数可以更改属性成员, 而常对象的非mutable成员属性是不允许被更改的,所以常对象只能调用常函数
}
int main() {
	test01();
	system("pause");
	return 0;
}
