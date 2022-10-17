#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal {
public:
	int m_Age;
	Animal() {
		m_Age = 100;
	}
};

class Sheep : virtual public Animal {
public:
	Sheep() {
		cout << "Sheep �Ĺ��캯��ִ��,m_Age���ı�֮ǰ��ֵΪ:" << m_Age << endl;//100
		m_Age = 20;
	}
};

class Camel :virtual public Animal {
public:
	Camel() {
		cout << "Camel �Ĺ��캯��ִ��,m_Age���ı�֮ǰ��ֵΪ:" << m_Age << endl;//20
		m_Age = 80;
	}
};

class Alpaca :public Sheep, public Camel {
public:
	int m_B;
};

class Alpaca2 :public Camel,public Sheep  {
public:
	int m_B;
};
void test01() {
	Alpaca a;
	Alpaca2 a2;
	//cout << a.m_Age << endl;// ������,���岻��ȷ,ͨ����������
	//cout << a.Sheep::m_Age << endl; //20
	//cout << a.Camel::m_Age << endl; //80
	//ͨ������ ����� ���̳� Animal�� m_Age,

	cout << a.m_Age << endl;// 80
	// Animal �� Sheep ,Camel �� �Ķ���m_Age ����һ�� �������ϵ�һ����ַ,��̳е�˳���Ӱ�칹�캯����ִ��,����ͨ��Animal�Ĺ��캯����m_Age=100,Ȼ���Ǹ����20,�����80
	cout << a2.m_Age << endl;// 20
	// Animal �� Sheep ,Camel �� �Ķ���m_Age ����һ�� �������ϵ�һ����ַ,����ͨ��Animal�Ĺ��캯����m_Age=100,Ȼ���Ǹ����80,�����20
		
		// �ܵĴ�ӡ��֤�������
		//Sheep �Ĺ��캯��ִ��, m_Age���ı�֮ǰ��ֵΪ:100
		//Camel �Ĺ��캯��ִ��, m_Age���ı�֮ǰ��ֵΪ : 20
		//Camel �Ĺ��캯��ִ��, m_Age���ı�֮ǰ��ֵΪ : 100
		//Sheep �Ĺ��캯��ִ��, m_Age���ı�֮ǰ��ֵΪ : 80
		//80
		//20
	

}

int main() {
	test01();
	system("pause");
	return 0;
}
