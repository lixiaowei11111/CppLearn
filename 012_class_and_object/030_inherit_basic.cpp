#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Dog {
public:
	void body() {
		cout << "����������" << endl;
	}
	void header() {
		cout << "�������Դ�" << endl;
	}
};

class BlackDog :public Dog {
public:
	void color() {
		cout << "black dog �Ĺ�ë�Ǻ�ɫ��" << endl;
	}
};

class WhiteDog :public Dog {
public:
	void color() {
		cout << "white dog��ë�ǰ�ɫ��" << endl;
	}
};

void test01() {
	BlackDog bd;
	bd.header();
	bd.body();
	bd.color();

	WhiteDog wd;
	wd.header();
	wd.body();
	wd.color();
}

int main() {
	test01();
	system("pause");
	return 0;
}
