#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::string;


// ����һ�� point ��, ���� x��y ������
class Point {

public:
	// ���� x,y
	void setPointX(int x);
	void setPointY(int y);

	// ��ȡ x,y
	int getPointX();
	int getPointY();
private:
	int m_X;
	int m_Y;
};
