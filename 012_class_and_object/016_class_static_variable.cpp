#include <iostream>

using std::cout;
using std::endl;
using std::string;


//���ж�����ͬһ������(����ͨ������� `ClassName::staticMember`)
//�ڱ���׶η����ڴ�
//��������, �����ʼ��
class Person {
public:
	static int m_Age;// class ������
private:
	static int m_Width;// static Ҳ����Ȩ������

};


//class�� ��ʼ��
int Person::m_Age = 20;

void test01();


int main() {
	test01();
	system("pause");
	return 0;
}
void test01() {
	//1.int Person::m_Age = 20;// error ��ǰ��Χ�޷������Ա Person::m_Age
	Person p;
	cout <<"p.m_Age: " << p.m_Age << endl;//20
	Person p2;
	cout << "p2.m_Age: " << p2.m_Age << endl;//20
	// 2.��̬��Ա���������˽�г�Ա,�ڶ���֮���ǹ���ͬһ�����ݵ�,  ��js��ͬ����,c++�е���ʾ���ǿ��Է��� ��̬��Ա��
	p2.m_Age = 40;
	cout << "p.m_Age: " << p.m_Age << endl;//40

	//3. class�ж���� static ��Ա �������Ƕ����� �����ϵ�, ʵ����������޸ĵĶ���ͬһ������,����ͨ����������, ͬʱ staticҲ�������� public,private,protectȨ�޵�
	cout << Person::m_Age << endl;//40
	//cout << Person::m_Width << endl; static��Ȩ��


}