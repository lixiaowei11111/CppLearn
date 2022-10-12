#include <iostream>

using std::cout;
using std::endl;
using std::string;


// 继承的三种方式 public protected private
class Father {
public:
	int a;
protected:
	int b;
private :
	int c;
public:
	Father() {
		a = b = c = 1;
	}
};


// 1.public 继承, 继承父类中有权限继承的成员(public, protected),权限在子类中保持不变
class Son1 :public Father {
public:
	int d;
};
void test01() {
	Son1 s1;
	cout << s1.a << endl;//1
	//cout << s1.b << endl;// protected 成员实例无权访问
	//cout << s1.c << endl// private成员 无权访问
}

// 2.protected 继承, 继承父类中有权限继承的成员(public, protected),继承的成员在子类中的权限全部变为protected
class Son2 :protected Father {
public:
	int d;
};
void test02() {
	Son2 s2;
	//cout << s2.a << endl;// protected 成员实例无权访问
	//cout << s2.b << endl;// protected 成员实例无权访问
	//cout << s2.c << endl// private成员 无权访问
}

// 2.private 继承, 继承父类中有权限继承的成员(public, protected),继承的成员在子类中的权限全部变为private
class Son3 :private Father {
public:
	int d;
};
void test03() {
	Son3 s3;
	//cout << s3.a << endl;// private 成员实例无权访问
	//cout << s3.b << endl;// private 成员实例无权访问
	//cout << s3.c << endl// private成员 无权访问
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
