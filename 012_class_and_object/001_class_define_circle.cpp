#include<iostream>
#include<string>
#define PI 3.14

using std::cout;
using std::endl;
using std::string;


// ��Ķ���, ����һ��Բ ��,����Բ�����Ժͷ���, ͬʱ���Լ���Բ���ܳ�
class MyCircle {
	// ����Ȩ��
	// public ����Ȩ��
	public:
		// Բ�İ뾶, ��Բ��һ������
		int m_r;
	// ��Ϊ
	//����Բ�ε��ܳ�
		double calculatePerimeter() {
			return 2 * PI * m_r;
		};
	private:
		string shape="round";

};

int main1() {

	// ʵ���� circle ��
	MyCircle circle;

	// ��Ĺ������� ���� . �ķ�ʽ������, ��ʵ�����Խ��и�ֵ
	circle.m_r = 2;

	cout << circle.calculatePerimeter() << endl;
		

	system("pause");
	return 0;
}