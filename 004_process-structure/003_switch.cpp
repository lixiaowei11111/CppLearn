#include<iostream>

using namespace std;

int main3() {
	int score;
	cout << "请给这部电影打分" << endl;
	cin >> score;
	cout << "您输入的分数为" << score << endl;
	switch (score) {
		case 10:
			cout << "您认为这部电影很优秀" << endl;
		break;
		case 9:
			cout << "您认为这部电影很优秀" << endl;
			break;
		case 8:
			cout << "您认为这部电影很优秀" << endl;
			break;
		case 7:
			cout << "您认为这部电影比较优秀" << endl;
			break;
		default:
			cout << "这部电影很烂!" << endl; break;
	}
	system("pause");
	return 0;
}