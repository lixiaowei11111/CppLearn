#include "circle.h"
// 设置半径和圆心
void Circle::setRadius(int r) {
	m_R = r;
}
void Circle::setCenter(Point& p) {
	m_C = p;
}

// 读取圆心和半径
int Circle::getRadius() {
	return m_R;
}
Point& Circle::getCenter() {
	return m_C;
}