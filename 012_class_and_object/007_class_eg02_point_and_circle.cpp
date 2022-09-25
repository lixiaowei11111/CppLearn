#include<iostream>
#include "circle.h"
using std::cout;
using std::endl;
using std::string;

// 全局函数,用于判断 点和圆的位置关系
void getPointAndCircleDistance(Circle& c, Point& p) {
	int p_X = p.getPointX();
	int p_Y = p.getPointY();

	int c_R = c.getRadius();
	Point c_P = c.getCenter();
	int c_X = c_P.getPointX();
	int c_Y = c_P.getPointY();

	int distance = (p_X - c_X) * (p_X - c_X)+(p_Y-c_Y)*(p_Y - c_Y);

	if (distance > (c_R * c_R)) {
		cout << "点在圆外" << endl;
	}
	else if (distance == (c_R * c_R)) {
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
};

int main7() {
	// 1.0设置圆类
	Circle c1;
	c1.setRadius(9);
	// 1.1设置圆心点
	Point p1;
	p1.setPointX(10);
	p1.setPointY(0);
	c1.setCenter(p1);
	
	// 设置点
	Point p2;
	p2.setPointX(10);
	p2.setPointY(10);
	getPointAndCircleDistance(c1, p2);

	system("pause");
	return 0;
}