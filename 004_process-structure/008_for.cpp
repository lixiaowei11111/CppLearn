#include<iostream>

using namespace std;

int main8() {
	// 1-100��,�ҳ���λ������7,����10λ������7,������7�ı�����,��ӡ������;
	for (int i = 1; i < 100; i++) {
		if (i / 10 ==  7 || i % 10 ==  7 || i % 7 == 0) {
			cout << "������" << i << endl;
		}
	}
	system("pause");
	return 0;
}