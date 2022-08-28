#include<iostream>

using namespace std;

int main1() {


	// 判断输入的三个数字谁最大
	int a = 0;
	int b = 0;
	int c = 0;
	cout << "请输如三个最大的数字" << endl;
	cout << "请输入数字a" << endl;
	cin >> a;
	cout << "请输入数字b" << endl;
	cin >> b;
	cout << "请输入数字C" << endl;
	cin >> c;
	if (a > b) {
		if (a > c) {
			cout << "a是这三个数字中最大的" << endl;
		}else if(a == c){
			cout << "a和c相等,都比b大" << endl;
		}
		else {
			cout << "c是这三个数中最大的" << endl;
		}
	}
	else if (a == b) {
		if (a > c) {
			cout << "a和b相等且是这三个数字中最大的" << endl;
		}
		else if (a == c) {
			cout << "a和b和c相等" << endl;
		}
		else {
			cout << "c是这三个数中最大的" << endl;
		}
	}
	else {
		if (b > c) {
			cout << "b是这三个数字中最大的" << endl;
		}
		else if (b == c) {
			cout << "b和c相等,都比a大" << endl;
		}
		else {
			cout << "c是这三个数中最大的" << endl;
		}
	}


	system("pause");
	return 0;
}