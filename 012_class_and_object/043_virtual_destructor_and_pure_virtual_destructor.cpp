#include <iostream>

using std::cout;
using std::endl;
using std::string;


class Animal {
public:
	Animal() {
		cout << "Animal constructor func execute" << endl;
	}
	/*~Animal() {
		cout << "Animal destructor func execute" << endl;
	}*/
	// ��������ǰ���� virtual �������������
	/*virtual ~Animal() {
		cout << "Animal virtual destructor func execute" << endl;
	}*/
	// ������������, ��Ҫ�������������
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};
// ���麯�� ��Ҫ����������
Animal::~Animal() {
	cout << "Animal pure virtual destructor func execute" << endl;
}
//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ������

class Cat :public Animal {
public:
	string* m_Name;
	Cat(string str) {
		m_Name = new string(str);
		cout << "Cat constructor func execute" << endl;
	}
	virtual void speak() {
		cout << *m_Name << "��˵��" << endl;
	}
	~Cat() {
		if (m_Name != NULL) {
			delete m_Name;
			cout << "Cat destructor func execute" << endl;
		}
	}
};


void test01() {
	Animal* cat = new Cat("TOM");
	cat->speak();
	
	// ���� ���ഴ����ʵ��, ��delete ��������ʱ, ����ִ���������������, �����ᵼ�������е�m_Name�Ķ�������δ��ɾ��,�Ӷ����¿ռ��˷�,�ڴ�й¶
	//ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
	//��ô���������������һ������������,  �������ʹ�� Cat�е���������ִ��
	//���������������������ͨ������ָ���ͷ��������
	delete cat;
};

int main() {
	test01();
	system("pause");
	return 0;
}
