#include<iostream>


using std::cout;
using std::endl;
using std::string;

// 类中构造函数的分类
class Person {
public:
	// 1. 按照有无参数分类, 有参构造 和 无参构造(无参构造又叫做默认构造, 编译器自动调用的构造函数没有参数)

	//1.1 无参构造
	Person() {
		age = 0;
		cout << "无参构造调用" << endl;
	}
	//1.2 有参构造
	Person(int a) {
		age = a;
		cout << "有参构造调用" << endl;
	}

	//2. 按照类型分为 普通构造 和 拷贝构造
	//2.1 上述皆为普通构造函数

	//2.2 拷贝构造
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造调用" << endl;
	}
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
	int age;
};




void main() {
	// 3. 构造函数调用方法 三种

	//1. 括号法
	Person p1;// 默认构造函数调用
	Person p2(10);// 有参构造函数调用
	Person p3(p2);// 拷贝构造函数调用
	//Person p4()
	// 注意点1:不能使用着这种方法来调用构造函数, 因为编译器认为这是一个 返回Person类的函数声明,而不会认为在创建(实例化)一个对象

	//2.显示法
	Person p5;
	Person p6 = Person(10);// 有参构造
	Person p7 = Person(p6);// 拷贝构造

	// Person(10) ; 
	//匿名对象 特点: 当前执行结束后,系统会立即回收掉匿名对象

	// 注意点2:
	// 不要用拷贝构造函数来初始化一个匿名对象 
	//Person(p7);// 报错 p7 重定义 
	// 编译器会认为 Person(p7) 等价于 Person p7(对象声明,即在实例化一个 p3的Person实例对象)
	Person* p8 = new Person(10); // 使用new 创建指针变量p8 来接收class实例对象
	cout<< p8->age <<endl;// 10

	//3. 隐式转换法
	Person p10 = 10;// 相当于 Person p10 = Person(10);
	Person p11 = p10;// 相当于 Person p11=Person(p10);
	system("pause");
}