#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Father {
public:
	Father() {
		cout << "父类构造函数执行" << endl;
	}
	~Father() {
		cout << "父类析构函数执行" << endl;
	}
};

class Son :public Father {
public:
	Son() {
		cout << "子类构造函数被执行" << endl;
	}
	~Son() {
		cout << "子类析构函数被执行" << endl;
	}
};

void test01() {
	Father f;
}

void test02() {
	Son s;
	// 父类构造函数执行
	// 子类构造函数被执行
	// 子类析构函数被执行
	// 父类析构函数执行

}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
