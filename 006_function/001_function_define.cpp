#include<iostream>


using namespace std;


// 1.����һ�������ֵ�ĺ���,����������
int maxMy(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}



int main1() {
	cout << "5��10˭��" << maxMy(5, 10) << endl;


	system("pause");
	return 0;
}


