#include<iostream>


using namespace std;


// 提前声明函数可以,  声明可以有多次,定义 有多次
void addFun(int param1, int param2);


int main2() {
	
	addFun(2000,10); //2000 10


	// lambda (箭头函数)
	/*a = [](int x, int y)->int {int z = x + y; return z; };*/
	system("pause");
	return 0;
}


//1. 默认参数
//void addFun(int param1=20, int param2) { // 默认实参不在形参列表的结尾
void addFun(int param1, int param2 = 20) {
	cout << "param1:" << param1 << "\t" << "有默认值param2:" << param2 << endl;
};