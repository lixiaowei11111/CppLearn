#include <iostream>

using std::cout;
using std::endl;
using std::string;

//���г�Ա����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class Person {
public:
	static int a;
	int b;
	static void func01(int b) {
		a = b;
		// ��̬��Աֻ�ܷ��� ��̬����, ��Ϊ��̬��Ա������ֻ����һ��, ������ ��ͨ����ʱ,����ͨ�����Ǹ����ඨ���ʵ�����仯��,�ж����ַ�ϴ����� ����ͨ����,�϶��ǲ�������ʺ��޸ĵ�
		//cout << b << endl;//��̬��Ա���� �������ȡ��ͨ����
		//b = 20;//��̬��Ա���� �������޸���ͨ����
	}
private:
	static void func02();// ��̬��Ա����ͨ��Աһ��,�յ�Ȩ�����η���Ӱ��
};

int Person::a = 20;
//int Person::func02(){}// ���ܷ��� private

void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	Person p;
	cout << "p.a: " << p.a << endl;//20 ͨ�� ʵ������
	cout << "Peson::a :" << Person::a << endl;//20 ͨ�������

	// ʵ������ static memeber function
	p.func01(30);
	cout << "p.a: " << p.a << endl;//30 ͨ�� ʵ������
	cout << "Peson::a :" << Person::a << endl;//30 ͨ�������

	// �� ������� static member function
	Person::func01(100);
	cout << "p.a: " << p.a << endl;//100 ͨ�� ʵ������
	cout << "Peson::a :" << Person::a << endl;//100 ͨ�������


}