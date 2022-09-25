#include<iostream>

using std::cout;
using std::endl;
using std::string;

// 建造一个立方体类
class Cube {
public:
	// set
	void setLength(int length) {
		c_L = length;
	};
	void setWidth(int width) {
		c_W = width;
	};
	void setHeight(int height) {
		c_H = height;
	};
	// get
	int getLength() {
		return c_L;
	};
	int getWidth() {
		return c_W;
	};
	int getHeight() {
		return c_H;
	};
	int getArea() {
		return(c_L * c_H + c_L * c_W + c_W * c_H) * 2;
	};
	int getBulk() {
		return c_L * c_W * c_H;
	};
	// 比较两个立方体是否相等的成员方法
	bool isSamec1(Cube& c1, Cube& c2) {
		// 引用传递
		return c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight();

	}



private:
	int c_L=0;
	int c_W=0;
	int c_H=0;
};

// 比较两个立方体是否相等的全局方法
bool isSamec1(Cube c1, Cube c2) {
	// 值传递
	return c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight();

}

int main6() {
	Cube c1;
	c1.setWidth(10);
	c1.setHeight(10);
	c1.setLength(10);
	Cube c2;
	c2.setWidth(10);
	c2.setHeight(10);
	c2.setLength(10);
	Cube c3;
	c3.setWidth(10);
	c3.setHeight(10);
	c3.setLength(12);
	cout << "长:" << c1.getLength() << endl;
	cout << "宽:" << c1.getWidth() << endl;
	cout << "高:" << c1.getHeight() << endl;
	cout << "面积:" << c1.getArea() << endl;
	cout << "体积:" << c1.getBulk() << endl;
	cout << (isSamec1(c1, c2) ? "相等" : "不相等") << endl;// 相等
	cout << (c1.isSamec1(c1, c3) ? "相等" : "不相等") << endl;// 不相等
	system("pause");
	return 0;
}