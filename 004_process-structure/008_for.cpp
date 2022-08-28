#include<iostream>

using namespace std;

int main8() {
	// 1-100中,找出个位数含有7,或者10位数含有7,或者是7的倍数的,打印敲桌子;
	for (int i = 1; i < 100; i++) {
		if (i / 10 ==  7 || i % 10 ==  7 || i % 7 == 0) {
			cout << "敲桌子" << i << endl;
		}
	}
	system("pause");
	return 0;
}