#include<iostream>


using namespace std;

// 1. 定义结构体, 先定义 Tool
struct Tool {
	int countPencil;//数量
};

// 2. 定义Teacher 结构体
struct Teacher {
	string name;
	int age;
	//struct Student { // 结构体里面定义 一个结构体 是非法的!
	//	string name; //姓名
	//	int age;//年龄
	//	int score;// 分数 // 不填写的话,和数组一样,默认
	//};
	Tool tool; // 创建一个结构体变量, 作为一个结构体, 合法的
};



int main4() {
	// 3. 创建Teacher结构体变量
	Teacher teacher;
	teacher.name = "张三丰";
	teacher.age = 108;
	teacher.tool.countPencil = 20;

	// 4. 创建指针变量, 指向该 结构体变量teacher
	Teacher* p = &teacher;

	// 5. 指针访问成员
	cout << "teacher下的tool的count: " << p->tool.countPencil << endl;// 20 正常访问



	return 0;
}