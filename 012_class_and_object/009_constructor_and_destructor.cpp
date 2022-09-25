#include<iostream>


using std::cout;
using std::endl;
using std::string;


// 1.构造函数 进行初始化的操作
//1. 构造函数,没有返回值也不写void
//2. 函数名称与类名相同
//3. 构造函数可以有参数, 因此可以发生重载
//4. 程序在调用对象时候会自动调用构造函数, 无序手动调用, 而且只会调用一次

class Constructor {
public:
	Constructor() {
		cout << "构造函数被调用" << endl;
	}
	/*1. 析构函数 进行清理的操作
	1. 析构函数,没有返回值也不写void
	2. 函数名称与类名相同,在名称前加上符号`~`
	3. 析构函数不可以有参数,因此不可以发生重载
	4. 程序在对象销毁前会自动调用析构函数,无须手动调用,而且只会调用一次
	*/
	~Constructor() {
		cout << "析构函数被调用" << endl;
	}
};

// 构造和析构都是必须有的实现,如果我们不提供,编译器会提供一个空实现的构造和析构
void test01() {
	Constructor c;// 局部变量,在栈区的数据,test01 执行完毕后,释放这个对象
}

void main() {
	//test01();// 局部变量 中的对象C 会在函数 执行完毕后被释放
	// 在main 函数中也需要等到main函数执行完毕后才能 执行析构和构造,所以比较难观察到
	Constructor c;


	system("pause");
}