#include<iostream>

using namespace std;

int main5() {
	// 1. �����ַ��� ����
	char ch = 'a';
	char ch4 = 'A';
	cout << ch << endl;
	//2. ����ռ�ÿռ��С
	cout << "char ����ռ�õĿռ��СΪ" << sizeof(ch) << "byte"<<endl;
	// 3. ���ͳ�������
	//char ch2 = "a"; �����ܱ���
	char ch3 = 'abc';
	// 4. ǿ������ת��, ��ĸ ��Ӧ��ASCII����
	cout << int(ch) << endl; // a ==> 97
	cout << int(ch4) << endl;// A ==> 65
	system("pause");
	return 0;
}