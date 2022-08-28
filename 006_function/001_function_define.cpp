#include<iostream>


using namespace std;


// 1.定义一个求最大值的函数,输入两个数
int maxMy(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}



int main1() {
	cout << "5和10谁大" << maxMy(5, 10) << endl;


	system("pause");
	return 0;
}


