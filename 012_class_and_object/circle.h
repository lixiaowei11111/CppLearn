#pragma once
#include "pointer.h"
class Circle {
public:
	// ���ð뾶��Բ��
	void setRadius(int r);
	void setCenter(Point& p);

	// ��ȡԲ�ĺͰ뾶
	int getRadius();
	Point& getCenter();
private:
	int m_R;
	Point m_C;
};