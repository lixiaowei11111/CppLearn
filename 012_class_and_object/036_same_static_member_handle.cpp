#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ͬ����̬���Ժ;�̬�����ķ���
//��̬��Ա����
//1.�ڱ���׶η����ڴ�
//2.��������, �����ʼ��
//��̬��Ա����  
//1.��̬��Աֻ�ܷ��� ��̬����, ��Ϊ��̬��Ա������ֻ����һ��, ������ 
//2.��ͨ����ʱ,����ͨ�����Ǹ����ඨ���ʵ�����仯��,�ж����ַ�ϴ����� ����ͨ����,�϶��ǲ�������ʺ��޸ĵ�

class Base {
public:
	static int m_A;
	static void func1() {
		cout << "Base static void func1()" << endl;
	};
	static void func1(int a) {
		cout << "Base static void func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	static int m_A;
	static void func1() {
		cout << "Son static void func1()" << endl;
	}
};
int Base::m_A = 100;
int Son::m_A = 200;

void test01() {
	Son s;
	cout << s.m_A << endl;// 200
	cout << s.Base::m_A << endl;// 100
	cout << Son::m_A << endl;// 200
	cout << Son::Base::m_A << endl;//100
	Son::func1();// Son static void func1()
	Son::Base::func1();//Base static void func1()
	Son::Base::func1(100);//Base static void func1(int a)
}

int main() {
	test01();
	system("pause");
	return 0;
}
