#include<iostream>
using namespace std;

int main() {
	//1.���������       cpp �е���������
	int a = 1, b = 2;
	char c = 'a';
	double f = static_cast<double>(1) / 2;
	std::cout << 0.1+0.2 << a << b <<"\nchar:"<< c << "\nfloat:" << std::endl;
	std::cout << 30 - 1 << "\n" << 0.2 - 0.1 << std::endl;
	std::cout << 2 * 3 <<"\n" << 02. * 0.3 << std::endl;
	std::cout << f << "\n" << 0.1 / 0.2 << std::endl;
	std::cout << b%a << std::endl;
	int h = 2;
	int i = 2;
	std::cout << h++ << ++i << std::endl;
	int j = 3;
	int k = 3;
	std::cout << j-- << --k <<endl;

	//2.��ϵ�����
	int l = 10;
	short o = 11;
	string n = "ada";
	bool m = o == l;
	cout << m << endl;
	if (l==o) {
		cout << "o ���� l" << endl;
	}
	if (l != 0) {
		cout << "o ������ l" << endl;
	}
	if (l > 0) {
		cout << "o ���� l" << endl;
	}
	if (l < 0) {
		cout << "o С�� l" << endl;
	}
	if (l >=0) {
		cout << "o ���ڵ��� l" << endl;
	}
	if (l <= 0) {
		cout << "o С�ڵ��� l" << endl;
	}

	// 3. �߼������
	int t = 1;
	bool q = false;
	string r = "string";

	cout << "!t:" << !t << endl;// 0
	cout << "!q:" << !q << endl;// 1
	//cout << "!r:" << !r << endl;// string���Ͳ��ܱ�ǿת;
	int x = 1 && 2;
	int y = 1 || 2;
	int z = 10 || 0;
	cout << x<<y<<z<<endl;// 1 1 1

	// 4. λ�����
	int aA = 60; //0011 1100
	int bB = 13; //0000 1101
	int cC = 0b1000;
	// 4.1 ������ �� ���� &
	int dD = aA & bB;
	cout <<"������ �� ���� & :" << dD << endl;//12 0000 1100
	// 4.2 ������ �� ���� |
	int eE = aA | bB;
	cout <<" ������ �� ���� | :" << eE << endl;//61  0011 1101
	// 4.3 ������ �� ���� ~
	cout <<"������ �� ���� ~ :" << ~cC << endl;// -9 
	// 4.4 ������ ��� ���� ^
	int fF = aA ^ bB;
	cout <<"������ ��� ���� ^ :" << fF << endl;// 49
	// 4.5 ��������������� << ��һ���������ĸ�������λȫ����������λ����ߵĶ�����λ�������ұ߲�0��
	int gg = 0b1000 << 2;
	cout << "��������������� << :" << gg << endl;//32 100000
	// 4.6 ��������������� >> ��һ�����ĸ�������λȫ����������λ��������0��������1���ұ߶�����
	int hh = 0b1000 >> 2;
	cout <<"��������������� >> :" << hh << endl;//2 0010

	system("pause");
	return 0;
}