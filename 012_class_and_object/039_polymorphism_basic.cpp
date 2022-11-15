#include <iostream>

using std::cout;
using std::endl;
using std::string;
// ��̬��̬
// �������� �� ���������
// ����׶�ȷ��������ַ - ���

//��̬��̬
// ������ �� �麯��
// ���н׶�ȷ��������ַ - ���


class Animal {
public:
	// ����ǰ�� virtual �����η���ʾ �麯��
	virtual void speak() {
		cout << "Animal speak" << endl;
	}
};

class Cat:public Animal {
public:
	void speak() {
		cout << "Cat speak" << endl;
	}
};

class Dog:public Animal {
public:
	virtual void speak() {
		cout << "Dog speak" << endl;
	}
	// �������е� �麯�����η��ɼӿɲ���
};


void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	Cat c;
	Dog d;
	// Dog �� Cat ���еĶ��ڸ���� speak��������������д

	// ���� : �����������߷���ֵ��ͬ
	// ��д : ���������ͷ���ֵ ��ԭ����һ��
	doSpeak(c);
	doSpeak(d);
}

int main() {
	test01();
	system("pause");
	return 0;
}
