#include<iostream>


using std::cout;
using std::endl;
using std::string;

// ���й��캯���ķ���
class Person {
public:
	// 1. �������޲�������, �вι��� �� �޲ι���(�޲ι����ֽ���Ĭ�Ϲ���, �������Զ����õĹ��캯��û�в���)

	//1.1 �޲ι���
	Person() {
		age = 0;
		cout << "�޲ι������" << endl;
	}
	//1.2 �вι���
	Person(int a) {
		age = a;
		cout << "�вι������" << endl;
	}

	//2. �������ͷ�Ϊ ��ͨ���� �� ��������
	//2.1 ������Ϊ��ͨ���캯��

	//2.2 ��������
	Person(const Person& p) {
		age = p.age;
		cout << "�����������" << endl;
	}
	~Person()
	{
		cout << "������������" << endl;
	}
	int age;
};




void main() {
	// 3. ���캯�����÷��� ����

	//1. ���ŷ�
	Person p1;// Ĭ�Ϲ��캯������
	Person p2(10);// �вι��캯������
	Person p3(p2);// �������캯������
	//Person p4()
	// ע���1:����ʹ�������ַ��������ù��캯��, ��Ϊ��������Ϊ����һ�� ����Person��ĺ�������,��������Ϊ�ڴ���(ʵ����)һ������

	//2.��ʾ��
	Person p5;
	Person p6 = Person(10);// �вι���
	Person p7 = Person(p6);// ��������

	// Person(10) ; 
	//�������� �ص�: ��ǰִ�н�����,ϵͳ���������յ���������

	// ע���2:
	// ��Ҫ�ÿ������캯������ʼ��һ���������� 
	//Person(p7);// ���� p7 �ض��� 
	// ����������Ϊ Person(p7) �ȼ��� Person p7(��������,����ʵ����һ�� p3��Personʵ������)
	Person* p8 = new Person(10); // ʹ��new ����ָ�����p8 ������classʵ������
	cout<< p8->age <<endl;// 10

	//3. ��ʽת����
	Person p10 = 10;// �൱�� Person p10 = Person(10);
	Person p11 = p10;// �൱�� Person p11=Person(p10);
	system("pause");
}