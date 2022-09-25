#include<iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

// 类的 权限标识符 public private protected
//一个类可以有多个 public、protected 或 private 标记区域。
//每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。成员和类的默认访问修饰符是 private。

class PermissionClass {
	// public 公共 成员可以被 类内 和 实例访问
	string s_age;// 默认为私有类型
public:
	string s_name;

private:
	string s_id;

protected:
	int s_money;

public:
	// 类内 可以访问 任意该内中成员, 包括 public, private, protected
	void setDefault() {
		s_name = "张三";
		s_id = "114514";
		s_money = 115;
	};
};

int main3() {
	PermissionClass class1;
	class1.s_name = "11";// 类外 只能访问public
	//class1.s_age = "123";//编译器报错, 成员 PermissionClass::s_age 不可访问
	//class1.s_id = "123";// 编译器报错, s_id成员不可访问
	//class1.s_money = 123;// 编译器报错, s_money成员不可访问
	system("pause");
	return 0;
}