#include <iostream>

using namespace std;

class Base {
	static int f;
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son :public Base {
public:
	int d;
};
void test01() {
	Son s;
	cout << sizeof(s) << endl;// 16���ֽ�
	// ���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	// �����е�˽�г�Ա�Ǳ������� ������,��˷��ʲ���,��ȷʵ���̳���ȥ��
}



int main() {
	test01();
	system("pause");
	return 0;
}
