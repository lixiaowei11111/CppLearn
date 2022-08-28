#include<iostream>


using namespace std;

// 1. 定义结构体
struct Student {
	string name; //姓名
	int age;//年龄
	int score;// 分数 // 不填写的话,和数组一样,默认
}; 

int main3() {
	// 1. 创建学生结构体变量,     创建变量时 struct可忽略, 定义时必须要写
	struct Student Stu1 = {"张三",32,90};

	// 2. 创建指针变量 指向该地址
	Student* p = &Stu1;

	// 3.指针变量 访问 结构体成员, 通过 -> 符号
	cout << "  姓名: " << p->name << "  年龄: " << p->age << "  分数: " << p->score << endl;



	return 0;
}