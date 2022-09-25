#pragma once
#include "pointer.h"
class Circle {
public:
	// 设置半径和圆心
	void setRadius(int r);
	void setCenter(Point& p);

	// 读取圆心和半径
	int getRadius();
	Point& getCenter();
private:
	int m_R;
	Point m_C;
};