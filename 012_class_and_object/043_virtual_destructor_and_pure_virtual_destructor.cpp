#include <iostream>

using std::cout;
using std::endl;
using std::string;


class Animal {
public:
	Animal() {
		cout << "Animal constructor func execute" << endl;
	}
	/*~Animal() {
		cout << "Animal destructor func execute" << endl;
	}*/
	// 析构函数前加上 virtual 编程虚析构函数
	/*virtual ~Animal() {
		cout << "Animal virtual destructor func execute" << endl;
	}*/
	// 纯虚析构函数, 需要在类外具体声明
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};
// 纯虚函数 需要在类外声明
Animal::~Animal() {
	cout << "Animal pure virtual destructor func execute" << endl;
}
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat :public Animal {
public:
	string* m_Name;
	Cat(string str) {
		m_Name = new string(str);
		cout << "Cat constructor func execute" << endl;
	}
	virtual void speak() {
		cout << *m_Name << "在说话" << endl;
	}
	~Cat() {
		if (m_Name != NULL) {
			delete m_Name;
			cout << "Cat destructor func execute" << endl;
		}
	}
};


void test01() {
	Animal* cat = new Cat("TOM");
	cat->speak();
	
	// 基于 基类创建的实例, 在delete 堆区数据时, 不会执行子类的析构函数, 这样会导致子类中的m_Name的堆区数据未被删除,从而导致空间浪费,内存泄露
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数,  这样便可使得 Cat中的析构函数执行
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete cat;
};

int main() {
	test01();
	system("pause");
	return 0;
}
