#include<iostream>

using namespace std;

int main7() {
	// ��� ��λ���е�һ����ˮ�ɻ���
	int a = 100;

	// ȡ��a�ĸ�λ��, ʮλ��, �Ͱ�λ��
	
	do
	{
		int ge = a % 10;
		int shi = a / 10 % 10;
		int bai = a / 100;
		int total = ge * ge * ge + shi * shi * shi + bai * bai * bai;
		if (total == a) {
			cout << "ˮ�ɻ���:" << total << endl;
		}
		a = a + 1;
	} while (a<1000);
	system("pause");
	return 0;
}