#include<iostream>
using namespace std;



int main8() {
	bool flag = false;
	cout << flag << endl; // 0
	flag = true;
	cout << flag << endl; // 1
	cout << "bool类型的占用空间大小" << sizeof(flag) <<"byte" << endl;// 1

	system("pause");
	return 0;

}