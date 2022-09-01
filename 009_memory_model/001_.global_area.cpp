#include<iostream>
#include<string>

using std::cout;
using std::endl;

// 1.����ȫ�ֱ���
int g_a = 123;
int g_b = 456;

//4.���徲̬ȫ�ֱ���
static int s_g_a = 123;
static int s_g_b = 456;

//6. ����ͳ�ʼ�� ȫ�ֳ���
const int c_g_a = 123;
const int c_g_b = 456;

int main1() {
	//2. ����ֲ�����
	int l_a = 123;
	int l_b = 345;
	cout << "ȫ�ֳ��� g_a�ĵ�ַΪ:  " << (int)&g_a << endl;
	cout << "ȫ�ֳ��� g_b�ĵ�ַΪ:  " << (int)&g_b << endl;
	cout << "�ֲ����� l_a�ĵ�ַΪ:  " << (int)&l_a << endl;
	cout << "�ֲ����� l_b�ĵ�ַΪ:  " << (int)&l_b << endl;

	//3. ���徲̬�ֲ�����, ʹ�� static
	static int s_l_a = 123;
	static int s_l_b = 456;
	cout << "staticȫ�ֳ��� c_g_a�ĵ�ַΪ:  " << (int)&s_g_a << endl;
	cout << "staticȫ�ֳ��� c_g_b�ĵ�ַΪ:  " << (int)&s_g_b << endl;
	cout << "static�ֲ����� s_l_a�ĵ�ַΪ:  " << (int)&s_l_a << endl;
	cout << "static�ֲ����� s_l_b�ĵ�ַΪ:  " << (int)&s_l_b << endl;

	//4.const ���� �ֲ�����
	const int c_l_a = 123;
	const int c_l_b = 456;
	cout << "ȫ�ֳ��� c_g_a�ĵ�ַΪ:  " << (int)&c_g_a << endl;
	cout << "ȫ�ֳ��� c_g_b�ĵ�ַΪ:  " << (int)&c_g_b << endl;
	cout << "�ֲ����� c_l_a�ĵ�ַΪ:  " << (int)&c_l_a << endl;
	cout << "�ֲ����� c_l_b�ĵ�ַΪ:  " << (int)&c_l_b << endl;
	//5.�ַ�������
	cout << "�ַ��������ĵ�ַΪ" << (int)&"hello_world" << endl;


	system("pause");
	return 0;
}