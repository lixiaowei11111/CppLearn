#include<iostream>

using namespace std;

int main4(){
	// Ұָ��
	// �ڳ�����, �������� Ұָ��
	// (int *)0x1100 ����16��������ǿתΪ ָ�����͵�ֵ
	int* p = (int*)0x1100;// �������쳣,��ȡ����Ȩ�޳�ͻ
	cout << *p << endl;

	system("pause");
	return 0;
}