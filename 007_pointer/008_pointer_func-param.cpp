#include<iostream>

using namespace std;


// 1.����������,�ٶ����ʹ�ú���
void swap(int* p1, int* p2);



int main8() {
	// ָ��������������
	int a = 20;
	int b = 10;
	swap(&a, &b);// ��ʱ���������Ǵ�ֵ����,����ָ�����
	cout << "a��ֵ:" << a << "\n" << "b��ֵ" << b << endl;// 10 20
	system("pause");
	return 0;
}

// 2.���庯��
void swap(int* p1, int* p2) {
	int temp = *p2;// ��ȡp1ָ��ָ���ֵ
	*p2 = *p1;
	*p1 = temp;

}