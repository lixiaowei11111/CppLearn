#include<iostream>

using namespace std;

int main7() {
	// 求出 三位数中第一个的水仙花数
	int a = 100;

	// 取出a的个位数, 十位数, 和百位数
	
	do
	{
		int ge = a % 10;
		int shi = a / 10 % 10;
		int bai = a / 100;
		int total = ge * ge * ge + shi * shi * shi + bai * bai * bai;
		if (total == a) {
			cout << "水仙花数:" << total << endl;
		}
		a = a + 1;
	} while (a<1000);
	system("pause");
	return 0;
}