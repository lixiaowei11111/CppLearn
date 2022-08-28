#include<iostream>


using namespace std;

int main() {
	// 1.int输入
	int v1 = 2;
	cout << "int类型的初始值为" << v1 << endl;
	cin >> v1;
	cout << "你输入的整型值为:" << v1 << endl;
	// 2.float输入
	float v2 = 2.14f;
	cout << "float类型的初始值为" << v2 << endl;
	cin >> v2;
	cout << "你输入的float值为:" << v2 << endl;
	// 3.char输入
	char v3 = 'a';
	cout << "char类型的初始值为" << v3 << endl;
	cin >> v3;
	cout << "你输入的整型值为:" << v3 << endl;
	// 4.string 输入
	string v4 = "121321";
	cout << "int类型的初始值为" << v4 << endl;
	cin >> v4;
	cout << "你输入的整型值为:" << v4 << endl;
	// 5.bool 输入
	bool v5 = false;
	cout << "int类型的初始值为" << v5 << endl;
	cin >> v5;
	cout << "你输入的整型值为:" << v5 << endl;

	system("pause");
	return 0;
}