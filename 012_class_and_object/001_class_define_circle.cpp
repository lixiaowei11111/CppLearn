#include<iostream>
#include<string>
#define PI 3.14

using std::cout;
using std::endl;
using std::string;


// 类的定义, 定义一个圆 类,包括圆的属性和方法, 同时可以计算圆的周长
class MyCircle {
	// 访问权限
	// public 公共权限
	public:
		// 圆的半径, 是圆的一个属性
		int m_r;
	// 行为
	//计算圆形的周长
		double calculatePerimeter() {
			return 2 * PI * m_r;
		};
	private:
		string shape="round";

};

int main1() {

	// 实例化 circle 类
	MyCircle circle;

	// 类的公共属性 可以 . 的方式来访问, 给实例属性进行赋值
	circle.m_r = 2;

	cout << circle.calculatePerimeter() << endl;
		

	system("pause");
	return 0;
}