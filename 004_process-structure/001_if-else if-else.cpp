#include<iostream>

using namespace std;

int main1() {


	// �ж��������������˭���
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "������������������" << endl;
	cout << "����������a" << endl;
	cin >> a;
	cout << "����������b" << endl;
	cin >> b;
	cout << "����������C" << endl;
	cin >> c;
	if (a > b) {
		if (a > c) {
			cout << "a������������������" << endl;
		}else if(a == c){
			cout << "a��c���,����b��" << endl;
		}
		else {
			cout << "c����������������" << endl;
		}
	}
	else if (a == b) {
		if (a > c) {
			cout << "a��b�����������������������" << endl;
		}
		else if (a == c) {
			cout << "a��b��c���" << endl;
		}
		else {
			cout << "c����������������" << endl;
		}
	}
	else {
		if (b > c) {
			cout << "b������������������" << endl;
		}
		else if (b == c) {
			cout << "b��c���,����a��" << endl;
		}
		else {
			cout << "c����������������" << endl;
		}
	}


	system("pause");
	return 0;
}