#include<iostream>
using std::cout;
using std::endl;
using std::string;


// �������캯�������õ�ʱ��
/*
	1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
	2. ֵ���ݵķ�ʽ��������������
	3. ��ֵ��ʽ���ؾֲ�����
*/

class Person {
public:
	int m_age;
	//1. Ĭ�Ϲ���
	Person() {
		m_age = 0;
		cout << "�޲ι��챻����" << endl;
	}
	//2.�вι���
	Person(int age) {
		m_age = age;
		cout << "�вι��챻����" << endl;
	}
	//3. �������캯��
	Person(const Person& p) {
		cout << "�������캯��������" << endl;
		m_age = p.m_age;
	}
	// 4. ��������
	~Person() {
		cout << "��������������" << endl;
	}
private:
	
};

// 1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���, ����Զ����ÿ������캯��
void test01() {
	Person p1(10);// �вι��캯��������
	Person p2(p1);// �������캯��������
	cout << "p1.m_age: " << p1.m_age << endl;
	cout << "p2.m_age: " << p2.m_age << endl;

}
// 2.ֵ���ݵķ�ʽ��������������,����Զ����ÿ������캯��
void doWork(Person p) {

}

void test02() {
	Person p3(10);// �вι��챻����
	doWork(p3);// �������캯��������  �����βν��յ�����ʱ,��������ʽ���� ,������ void doWork(Perosn p=p3), Ϊ���캯������ʽת����
	// �����β� ֵ����ʱ�����Ķ���Ϊ,��������ֵ ��ֵ������ֲ������β�
	// ��������,�����β�Ĭ��ֵ void doWork(Person p= Person p4(10)); ���������p3 ʱ,���������void doWork(Person p= p3); ���캯������ʽת����д��
}

//3. ��ֵ��ʽ���ؾֲ�����, ����Զ����� �������캯��
Person doWork02() {
	Person p1;// �޲ι��챻����
	cout <<(int*) & p1 << endl;
	return p1;
}

void test03() {
	Person p4 = doWork02();// �������챻����
	// �漰�����ֵ�����õ�, �����Զ����� �������캯��
	cout << (int*) & p4 << endl;

}

void main() {
	//test01();
	//test02();
	test03();



	system("pause");
}