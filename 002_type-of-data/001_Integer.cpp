/*
�������� ֮ ����
���ͷ�Ϊ 4 �� ��ռ �ڴ�ռ�����

 
bit   λ     ռ�� 0 �� 1 �������ֻ�����Ԫ
byte �ֽ�     1byte = 8bit ���� byte�� �ռ��СΪ 2^8, ȡֵ��Χλ -128~127 ����0

short 2�ֽ� -2^15~2^15-1
int   4�ֽ� -2^31~2^31-1
long  32λϵͳΪ 4���ֽ� -2^31~2^31-1
long long 8�ֽ� -2^63~2^63-`
*/

#include<iostream>
using namespace std;

int main1() {

	// 1. ������
	short num1 = 32768;// �������ֵ��ѴӸ�����ʼ�㳬���Ĳ���
	//short num1 = 123;
	// 2. ����
	int num2 = 32768;
	// 3. ������
	long num3 = 32768;
	// 4. ��������
	long long num4 = 32768;
	cout << "������num1" << num1 << endl;
	cout << "����num2" << num2 << endl;
	cout << "������num3" << num3 << endl;
	cout << "��������num4" << num4 << endl;
	system("pause");
		return 0;
}