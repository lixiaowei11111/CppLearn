#include "circle.h"
// ���ð뾶��Բ��
void Circle::setRadius(int r) {
	m_R = r;
}
void Circle::setCenter(Point& p) {
	m_C = p;
}

// ��ȡԲ�ĺͰ뾶
int Circle::getRadius() {
	return m_R;
}
Point& Circle::getCenter() {
	return m_C;
}