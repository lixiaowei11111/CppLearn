#include<iostream>

using namespace std;

int main6() {
	// 1. ����ָ��������һά�����е�ÿһ��Ԫ��
	int arr[4] = { 1,2,3,4 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int * p = arr;// ָ��ָ������� �׵�ַ
	for (size_t i = 0; i < length; i++)
	{
		cout << "arr[" << i << "]�ĵ�ַΪ" << (long long)p << endl;
		cout << "arr[" << i << "]��ֵΪ" <<  *p << endl;
		p++;// p=p+1 ÿ�μ� int���͵� byte
	}

	system("pause");
	return 0;
}