#include<iostream>


using namespace std;

// 1. 定义结构体
struct student {
	string name; //姓名
	int age;//年龄
	int score;// 分数
}; // 结构体变量创建方式3

int main2() {
	
	// 2.创建结构体体数组变量
	student stuArr[3] = { {"张三",32,90},{"李四",12,40},{"王五",23,87} };

	// 3. 给结构体数组中的元素赋值
	stuArr[2].name = "赵六";
	stuArr[2].age = 88;
	stuArr[2].score = 100;

	// 4.便利结构体中的数据
	int length = sizeof(stuArr) / sizeof(stuArr[0]);

	for (size_t i = 0; i < length; i++)
	{
		cout << stuArr[i].name << "\t" << stuArr[i].age << "\t" << stuArr[i].score << "\t" << endl;
	}
	return 0;
}