#include <iostream>

using std::cout;
using std::endl;
using std::string;


//所有对象共享同一份数据(可以通过类访问 `ClassName::staticMember`)
//在编译阶段分配内存
//类内声明, 类外初始化
class Person {
public:
	static int m_Age;// class 内声明
private:
	static int m_Width;// static 也会有权限区分

};


//class外 初始化
int Person::m_Age = 20;

void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	//1.int Person::m_Age = 20;// error 当前范围无法定义成员 Person::m_Age
	Person p;
	cout <<"p.m_Age: " << p.m_Age << endl;//20
	Person p2;
	cout << "p2.m_Age: " << p2.m_Age << endl;//20
	// 2.静态成员是属于类的私有成员,在对象之间是共享同一份数据的,  和js不同的是,c++中的类示例是可以访问 静态成员的
	p2.m_Age = 40;
	cout << "p.m_Age: " << p.m_Age << endl;//40

	//3. class中定义的 static 成员 本质上是定义在 该类上的, 实例对象访问修改的都是同一份数据,可以通过类来访问, 同时 static也是有区分 public,private,protect权限的
	cout << Person::m_Age << endl;//40
	//cout << Person::m_Width << endl; static有权限


}