#include<iostream>

using namespace std;

int main() {
	//计算二维数组中的最大值
	int arr[3][3] = { {100,100,100},{90,500,100} , {30,100,40} };
	//1. 计算arr的 行长度
	int rowCount = sizeof(arr) / sizeof(arr[0]);
	//2. 计算arr的列数
	int colCount = sizeof(arr[0]) / sizeof(arr[0][0]);
	//3. 设置最大值
	int totalScore = 0;
	for (int i = 0; i < rowCount; i++) {
		int total=0;
		for (int j = 0; j < colCount; j++) {
			total = total + arr[i][j];
		}
		cout << "第" << i << "个人总分为:" << total << endl;
		if (total > totalScore) {
			totalScore = total;
		}
	}
	cout << "总分最高的是" << totalScore << endl;

	system("pause");
	return 0;
}