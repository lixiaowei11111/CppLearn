#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Dog {
public:
	void body() {
		cout << "狗有四条腿" << endl;
	}
	void header() {
		cout << "狗都有脑袋" << endl;
	}
};

class BlackDog :public Dog {
public:
	void color() {
		cout << "black dog 的狗毛是黑色的" << endl;
	}
};

class WhiteDog :public Dog {
public:
	void color() {
		cout << "white dog的毛是白色的" << endl;
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
