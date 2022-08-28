#include<iostream>
#include<time.h>
#include<cstdlib>

using namespace std;

int main5() {

	//1. 生成一个 0-100的随机数
	// rand() 会产生一个固定的随机数, 使用srand函数来重置
	srand((unsigned)time(NULL));
	int randomNumber = rand() % 100;// 取模100 生成 0-99的1整数
	int inputNumber;
	cout << "系统生成了一个随机数,请输入一个0-100的整数" <<randomNumber <<endl;
	cin >> inputNumber;
	while (inputNumber != randomNumber) {
		if (inputNumber > randomNumber) {
			cout << "你输入的数比系统生成的随机数要大" << endl;
		}
		else {
			cout << "你输入的数比系统生成的随机数要小" << endl;
		}
		cin >> inputNumber;
	}
	cout << "恭喜你猜对了" << endl;
	system("pause");
	return 0;
}