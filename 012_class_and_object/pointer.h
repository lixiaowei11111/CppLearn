#pragma once
#include<iostream>
using std::cout;
using std::endl;
using std::string;


// 定义一个 point 类, 包含 x和y 的坐标
class Point {

public:
	// 设置 x,y
	void setPointX(int x);
	void setPointY(int y);

	// 读取 x,y
	int getPointX();
	int getPointY();
private:
	int m_X;
	int m_Y;
};
