#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 制作饮品过程 煮水 - 冲泡 - 倒入杯中 - 加入辅料
class MakeDrink {
public:
	// 煮水
	virtual void boil() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒入杯中
	virtual void pour() = 0;
	//加入辅料
	virtual void material() = 0;

	// 制作
	void make() {
		boil();
		brew();
		pour();
		material();
	}
};

// 制作咖啡
class Coffee :public MakeDrink {
public:
	void boil() {
		cout << "加入农夫山泉" << endl;
	}
	void brew() {
		cout << "冲泡可可粉" << endl;
	}
	void pour() {
		cout << "导入玻璃杯中" << endl;
	}
	void material() {
		cout << "加入糖和玛莎拉" << endl;
	}
};

// 制作乌龙茶
class Tea :public MakeDrink {
public:
	void boil() {
		cout << "煮康师傅" << endl;
	}
	void brew() {
		cout << "冲泡龙井" << endl;
	}
	void pour() {
		cout << "导入茶杯中" << endl;
	}
	void material() {
		cout << "加入玛莎拉,多少带点臭" << endl;
	}
};

void doWorker(MakeDrink* drink) {
	drink->make();
	delete drink;
}


void test01() {
	doWorker(new Coffee);
	doWorker(new Tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}
