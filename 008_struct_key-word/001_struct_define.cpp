#include<iostream>


using namespace std;

// 1. 定义结构体
struct student {
	string name; //姓名
	int age;//年龄
	int score;// 分数
} stu3; // 结构体变量创建方式3

int main1() {
	// 1. 结构体变量创建方式1
	student stu1;
	stu1.name = "张三";
	stu1.age = 32;
	stu1.score = 89;

	cout << stu1.name << stu1.age << stu1.score << endl;

	// 2. 结构体变量创建方式2
	student stu2 = { "李四",24,78 };
	cout << stu2.name << stu2.age << stu2.score << endl;


	// 3.定义结构体的时候,顺便定义变量
	stu3.name = "王五";
	stu3.age = 22;
	stu3.score = 80;

	cout << stu3.name << stu3.age << stu3.score << endl;

	return 0;
}