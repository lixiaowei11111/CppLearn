#include<iostream>
using std::cout;
using std::endl;
using std::string;


// 拷贝构造函数被调用的时机
/*
	1. 使用一个已经创建完毕的对象来初始化一个新对象
	2. 值传递的方式给函数参数传参
	3. 以值方式返回局部变量
*/

class Person {
public:
	int m_age;
	//1. 默认构造
	Person() {
		m_age = 0;
		cout << "无参构造被调用" << endl;
	}
	//2.有参构造
	Person(int age) {
		m_age = age;
		cout << "有参构造被调用" << endl;
	}
	//3. 拷贝构造函数
	Person(const Person& p) {
		cout << "拷贝构造函数被调用" << endl;
		m_age = p.m_age;
	}
	// 4. 析构函数
	~Person() {
		cout << "析构函数被调用" << endl;
	}
private:
	
};

// 1. 使用一个已经创建完毕的对象来初始化一个新对象, 类会自动调用拷贝构造函数
void test01() {
	Person p1(10);// 有参构造函数被调用
	Person p2(p1);// 拷贝构造函数被调用
	cout << "p1.m_age: " << p1.m_age << endl;
	cout << "p2.m_age: " << p2.m_age << endl;

}
// 2.值传递的方式给函数参数传参,类会自动调用拷贝构造函数
void doWork(Person p) {

}

void test02() {
	Person p3(10);// 有参构造被调用
	doWork(p3);// 拷贝构造函数被调用  函数形参接收到参数时,进行了隐式调换 ,类似于 void doWork(Perosn p=p3), 为构造函数的隐式转换法
	// 函数形参 值传递时发生的动作为,将变量的值 赋值给这个局部变量形参
	// 声明函数,加上形参默认值 void doWork(Person p= Person p4(10)); 当传入参数p3 时,顶替掉即可void doWork(Person p= p3); 构造函数的隐式转换法写法
}

//3. 以值方式返回局部变量, 类会自动调用 拷贝构造函数
Person doWork02() {
	Person p1;// 无参构造被调用
	cout <<(int*) & p1 << endl;
	return p1;
}

void test03() {
	Person p4 = doWork02();// 拷贝构造被调用
	// 涉及到类的值被调用的, 都会自动调用 拷贝构造函数
	cout << (int*) & p4 << endl;

}

void main() {
	//test01();
	//test02();
	test03();



	system("pause");
}