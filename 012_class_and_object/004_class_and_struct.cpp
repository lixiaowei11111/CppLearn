#include<iostream>


using std::cout;
using std::cin;
using std::endl;

// class �ĳ�Ա Ĭ������Ϊ private
class test01 {
	int m_r;
};
//structΪ public
struct test02 {
	int m_r;
};

int main4() {
	test01 test01;
	//test01.m_r;// ��Ա "test01::m_r" ���ɷ���
	test02 test02;
	test02.m_r = 2;


	system("pause");
	return 0;
}