#include<iostream>

using namespace std;

int main() {
	//�����ά�����е����ֵ
	int arr[3][3] = { {100,100,100},{90,500,100} , {30,100,40} };
	//1. ����arr�� �г���
	int rowCount = sizeof(arr) / sizeof(arr[0]);
	//2. ����arr������
	int colCount = sizeof(arr[0]) / sizeof(arr[0][0]);
	//3. �������ֵ
	int totalScore = 0;
	for (int i = 0; i < rowCount; i++) {
		int total=0;
		for (int j = 0; j < colCount; j++) {
			total = total + arr[i][j];
		}
		cout << "��" << i << "�����ܷ�Ϊ:" << total << endl;
		if (total > totalScore) {
			totalScore = total;
		}
	}
	cout << "�ܷ���ߵ���" << totalScore << endl;

	system("pause");
	return 0;
}