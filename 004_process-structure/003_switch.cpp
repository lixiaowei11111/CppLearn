#include<iostream>

using namespace std;

int main3() {
	int score;
	cout << "����ⲿ��Ӱ���" << endl;
	cin >> score;
	cout << "������ķ���Ϊ" << score << endl;
	switch (score) {
		case 10:
			cout << "����Ϊ�ⲿ��Ӱ������" << endl;
		break;
		case 9:
			cout << "����Ϊ�ⲿ��Ӱ������" << endl;
			break;
		case 8:
			cout << "����Ϊ�ⲿ��Ӱ������" << endl;
			break;
		case 7:
			cout << "����Ϊ�ⲿ��Ӱ�Ƚ�����" << endl;
			break;
		default:
			cout << "�ⲿ��Ӱ����!" << endl; break;
	}
	system("pause");
	return 0;
}