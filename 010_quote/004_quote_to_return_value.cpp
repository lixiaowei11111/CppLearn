#include<iostream>

using std::cout;
using std::endl;


// ����һ��ȫ�ֱ���
double vals[] = { 1.23,3.14,6.28 };

// ����һ���������õĺ���
double& test01(int i);


// ���ܷ���һ���ֲ�����������
int& test02() {
	int i = 10;
	return i;
}
int main4() {

	//�ı�ֵ֮ǰ��ȫ�ֱ���
	for (size_t i = 0; i < 3; i++)
	{
		cout << "vals[" << i << "]: " << vals[i] << endl;
	}
	// ͨ�����غ���������ֵ�ı�
	test01(2) = 3.25;
	test01(0) = 3.25;

	//�ı�ֵ֮�������
	for (size_t i = 0; i < 3; i++)
	{
		cout << "vals[" << i << "]: " << vals[i] << endl;
	}
	cout<<test02()<<endl;// ����

	system("pause");
	return 0;
}

// ����һ�� �������õı���
double& test01(int i) {
	double& ref = vals[i];// ������ ָ��λ�� i��ֵ ����ַ���ñ�����
	return ref;
}
