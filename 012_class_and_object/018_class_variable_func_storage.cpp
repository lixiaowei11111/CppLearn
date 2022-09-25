#include <iostream>

using std::cout;
using std::endl;
using std::string;

// C++ 类成员按照以下方式划分,只有一种变量 会存在 类的对象(实例) 身上
class Person {
	int m_A;// 非静态成员变量 在实例身上
	static int m_b;// 静态成员变量 不在示例对象身上
	int func() { return 0; };// 非静态成员函数,不在实例对象身上
	static int function2() { return 0; };// 静态成员函数,不在实例对象身上
};
void test01() {
	/*class Person {

	};*/
	Person p;
	// 空 class的实例 内存占用大小为1个字节,
	//C++编译器会给每个空对象也分配一个内存空间,是为了区分空对象占内存的地址,每个空对象的地址也不能相同
	cout << "size of p: " << sizeof(p) << endl;// 1
}

void test02() {
	
	Person p1;
	// 一旦 class 不为空, 空对象也就不复存在, 原先占用的 1byte空间也就不会存在,而是按照成员里面的非静态成员变量的大小来计算
	cout << "size of p1: " << sizeof(p1) << endl;// 4
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
