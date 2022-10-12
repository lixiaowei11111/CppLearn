#include <iostream>
#include<math.h>

using std::cout;
using std::endl;
using std::string;
using std::pow;

// 友元函数 友元函数声明的关键字为 friend
class Pointer {
	friend void calcDistance(Pointer* p);
public:
	Pointer(int x,int y):m_X(x),m_Y(y) {
		cout << "有参构造函数被调用" << endl;
	}
private:
	int m_X;
	int m_Y;
	void getDsitance() {
		cout << "坐标距离原点的直线距离为: " << pow((m_X * m_X + m_Y * m_Y),0.5) << endl;
	}
};
void calcDistance(Pointer* p) {
	p->getDsitance();// 友元函数 访问私有属性
};

int main() {
	Pointer p(3,4);
	calcDistance(&p);//5
	system("pause");
	return 0;
}
