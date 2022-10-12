#include <iostream>

using namespace std;

class Base {
	static int f;
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son :public Base {
public:
	int d;
};
void test01() {
	Son s;
	cout << sizeof(s) << endl;// 16个字节
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中的私有成员是被编译器 隐藏了,因此访问不到,但确实被继承下去了
}



int main() {
	test01();
	system("pause");
	return 0;
}
