#include <iostream>

using std::cout;
using std::endl;
using std::string;

// thisָ�������
//1. ��������ͬ�����βκͳ�Ա����
//2.���Է���return *this(��������Ϊ��ʽ����)

class Person {
public:
	int age;
	Person(int age) {
		this->age = age;
		cout << "�вι��챻����" << endl;
	};
	// ��ʽ����
	Person& addAge(int age) {
		this->age += age;
		return *this;
	}
	// һ��Ҫ��������, ������ return Person& p2=*this, ����������������ͬ�ڷ��ص��� return Person p1=*this, �൱��ʹ����ʽת����ȥ�½���һ��Personʵ������,age�ĳ�ʼֵ��Զ���ǹ��캯���е�10
};

void test01() {
	//Person p1;//error ��class�����вι���ʱ,�����������ṩĬ�Ϲ���,���Իᱨ��
	Person p1(10);
	cout << p1.age << endl;//10

	Person p2(10);
	cout << p2.age << endl;//10

	p2.addAge(10).addAge(10).addAge(20);
	cout << p2.age << endl;//50
}

int main() {
	test01();
	system("pause");
	return 0;
}
