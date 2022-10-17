#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal {
public:
	int m_Age;
	Animal() {
		m_Age = 100;
	}
};

class Sheep : virtual public Animal {
public:
	Sheep() {
		cout << "Sheep 的构造函数执行,m_Age被改变之前的值为:" << m_Age << endl;//100
		m_Age = 20;
	}
};

class Camel :virtual public Animal {
public:
	Camel() {
		cout << "Camel 的构造函数执行,m_Age被改变之前的值为:" << m_Age << endl;//20
		m_Age = 80;
	}
};

class Alpaca :public Sheep, public Camel {
public:
	int m_B;
};

class Alpaca2 :public Camel,public Sheep  {
public:
	int m_B;
};
void test01() {
	Alpaca a;
	Alpaca2 a2;
	//cout << a.m_Age << endl;// 二义性,语义不明确,通过作用域解决
	//cout << a.Sheep::m_Age << endl; //20
	//cout << a.Camel::m_Age << endl; //80
	//通过定义 虚基类 来继承 Animal的 m_Age,

	cout << a.m_Age << endl;// 80
	// Animal 和 Sheep ,Camel 类 改动的m_Age 是在一个 虚基类表上的一个地址,多继承的顺序会影响构造函数的执行,先是通过Animal的构造函数让m_Age=100,然后是改造成20,最后是80
	cout << a2.m_Age << endl;// 20
	// Animal 和 Sheep ,Camel 类 改动的m_Age 是在一个 虚基类表上的一个地址,先是通过Animal的构造函数让m_Age=100,然后是改造成80,最后是20
		
		// 总的打印验证结果如下
		//Sheep 的构造函数执行, m_Age被改变之前的值为:100
		//Camel 的构造函数执行, m_Age被改变之前的值为 : 20
		//Camel 的构造函数执行, m_Age被改变之前的值为 : 100
		//Sheep 的构造函数执行, m_Age被改变之前的值为 : 80
		//80
		//20
	

}

int main() {
	test01();
	system("pause");
	return 0;
}
