#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 1. class 中的 拷贝构造函数默认为 浅拷贝, 利用new来开辟 堆区地址进行 深拷贝
class Person {
public:
	int m_Height;
	int* m_age;// int 类型的指针变量
	Person(int h,int a) {
		m_Height = h;
		m_age = new int(a);
		cout << "有参构造函数的调用" << endl;
	}
	Person(const Person& p) {
		m_Height = p.m_Height;
		//m_age = p.m_age;// 拷贝函数提供的就是类似于这种浅拷贝, 使用的变量来自于一个地址
		m_age = new int (*p.m_age);// 重新开辟一个堆区来存放值
		cout << "拷贝构造函数的调用" << endl;
	}
	~Person() {
		if (m_age != NULL) {
			delete m_age;// new 开辟的空间需要手动释放
			m_age = NULL;// 防止野指针
		}
		cout << "destructor 的调用" << endl;
	}
};
void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p1(180, 20);
	cout << "p1的身高:" << p1.m_Height << "\np1的年龄:" << *p1.m_age << endl;
	Person p2(p1);
	cout << "p2的身高:" << p2.m_Height << "\np2的年龄:" << *p2.m_age << endl;
}
