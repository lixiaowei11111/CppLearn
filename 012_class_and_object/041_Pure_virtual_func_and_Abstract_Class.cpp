#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
public:
	// ���麯��
	// class ��ֻҪ��һ�����麯��, �����ͱ���Ϊ ������
	// ��������ص�:
	// 1.�޷�ʵ��������
	// 2. ����������������д �����е� ���麯��, ����Ҳ�ᱻ��Ϊһ�� ������,ͬ�����ܱ�ʵ����
	virtual void speak() = 0;

};

class Son :public Base {

};

class Son2 :public Base {
public:
	void speak() {
		cout << "��д���麯��" << endl;
	}
};

void test01() {
	//Base base;// ӵ�� ���麯���ĳ����� ���ܱ�ʵ����
	// Son son;// �̳г�����,����û����д�����еĴ��麯����������, ͬ���޷�ʵ����
	Son2 *s=new Son2;
	s->speak();
}

int main() {
	test01();
	system("pause");
	return 0;
}
