#include <iostream>


using std::cout;
using std::string;
using std::endl;

// 内部定义函数
class Box1 {
public:
	// 类 内部定义函数 getVolume
	double getVolume(void) {
		return length * width * height;
	};
private:
	double length;
	double width;
	double height;
};

// 类 外部 通过范围**解析运算符** 来定义内中函数, 类中函数需要事先声明
class Box2 {
public:
	// 类 内部定义函数 getVolume
	double getVolume(void);
private:
	double length;
	double width;
	double height;
};
double Box2::getVolume(void) {
	return length * width * height;
};


int main() {




	system("pause");
	return 0;
}