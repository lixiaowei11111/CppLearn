#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

int main5() {

	//1. ����һ�� 0-100�������
	// rand() �����һ���̶��������, ʹ��srand����������
	srand((unsigned)time(NULL));
	int randomNumber = rand() % 100;// ȡģ100 ���� 0-99��1����
	int inputNumber;
	cout << "ϵͳ������һ�������,������һ��0-100������" <<randomNumber <<endl;
	cin >> inputNumber;
	while (inputNumber != randomNumber) {
		if (inputNumber > randomNumber) {
			cout << "�����������ϵͳ���ɵ������Ҫ��" << endl;
		}
		else {
			cout << "�����������ϵͳ���ɵ������ҪС" << endl;
		}
		cin >> inputNumber;
	}
	cout << "��ϲ��¶���" << endl;
	system("pause");
	return 0;
}