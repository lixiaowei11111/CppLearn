#include "pointer.h"
// ���� x,y
void Point::setPointX(int x) {
	m_X = x;
};
void Point::setPointY(int y) {
	m_Y = y;
};

// ��ȡ x,y
int Point::getPointX() {
	return m_X;
};
int Point::getPointY() {
	return m_Y;
};