#include<iostream>


using std::cout;
using std::cin;
using std::endl;

// class 的成员 默认属性为 private
class test01 {
	int m_r;
};
//struct为 public
struct test02 {
	int m_r;
};

int main4() {
	test01 test01;
	//test01.m_r;// 成员 "test01::m_r" 不可访问
	test02 test02;
	test02.m_r = 2;


	system("pause");
	return 0;
}