#include<iostream>

using std::cout;
using std::endl;


// 
void showValue(const int& ref) {
	// const���� ���ñ���ʱ, ���ñ���ָ���ֵҲ�����ٱ��޸�
	// ref = 20;// vs2022����, ���ʽ�����ǿ��޸ĵ���ֵ
	cout << ref << endl;
}


int main() {

	// ���������, �������ñ����ʼ��,����һ����������õ�ַ
	//ֱ�Ӹ���==��ֵ��Υ����
	//int& ref = 200;

	//const���� ����
	const int& ref = 200;
	//�൱�� int temp = 10;const int& ref = temp;
	//ref = 20;// const���κ�,��Ϊֻ������
	int a = 20;
	showValue(a);

	system("pause");
	return 0;
}