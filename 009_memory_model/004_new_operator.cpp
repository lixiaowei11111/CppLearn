#include<iostream>
using namespace std; // Ԥ���� �����ռ�Ϊ std����ĺ���



// ����new����һ������
double* test01() {
	return new double(3.14159); // new �ڶ�����������
};

// 2.���� new����һ������
void test02() {
	int* p = new int[10];// ������[]������� ����, ��ʾ���������10��Ԫ��

	for (size_t i = 0; i < 10; i++)
	{
		p[i] = 100 + i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << p[i] << endl;// 100 101 102 103 104 105 106 107 108 109
	}

	delete[]  p;
};


int main() {
	double* p1 = test01();


	cout << *p1 << endl;// 3.14159
	// ���������ݲ��ᱻ�������Զ��ͷ�,
	cout << *p1 << endl;//3.14159

	//ʹ��delete �ؼ����ͷ� ����, �﷨: delete ��ַ
	delete p1;

	//cout << *p1 << endl;// delete�ڶ���,��������ʾ:ӵ��δ��ʼ�����ڴ�p1

	test02();

	system("pause");
	return 0;
}