#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ��ָ���ڵ��� class�еķ���ʱ,������this����������,��Ϊ��ָ����û�и�����
class Person {
public:
	int m_Age;
	static int m_Height;
	void showClassName() {
		cout << "this is a Person class" << endl;
	}
	void showAge() {
		// ��ָ���� thisָ��ָ����û��m_Age���Գ�Ա��;
		cout << this->m_Age << endl;
	}
	void showHeight() {
		// ��ָ���� thisָ��ָ����û��m_Age���Գ�Ա��;
		cout << this->m_Height << endl;
	}
};

void test01() {
	Person* p = NULL;
	p->showClassName();
	//p->showAge();//Error ��ָ���� thisָ��ָ����û��m_Age���Գ�Ա��;
	//p->showHeight();
}

int main() {
	test01();
	system("pause");
	return 0;
}
