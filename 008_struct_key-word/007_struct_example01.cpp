#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


//2. 定义 Student结构体
struct Stu {
	string sName;
	int score;
};

// 1. 定义 Teacher结构体
struct Teacher {
	string tName;
	struct Stu stuArr[5];
};

// 4. 声明 给 结构体成员赋值的函数
void allocateSpace(struct Teacher tArray[], int len);

// 5. 声明打印出所有 memberd的value的函数
void printInfo(struct Teacher tArray[], int len);


int main7() {
	srand((unsigned)time(NULL));// 随机数种子
	//3. 创建Teacher 的结构体数组 
	struct Teacher teacherArr[3];
	int length = sizeof(teacherArr) / sizeof(teacherArr[0]);

	//8. 调用 赋值函数
	allocateSpace(teacherArr, length);

	//9.调用 打印函数
	printInfo(teacherArr, length);
	system("pause");
	return 0;
}

// 6. 定义赋值函数
void allocateSpace(Teacher tArray[], int len) {

	string nameSeed = "ABCDE";
	string tName = "Teacher_";
	string sName = "Student_";
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = tName + nameSeed[i];
		for (int j = 0; j < 5; j++) {
			tArray[i].stuArr[j].sName = sName + nameSeed[j];
			tArray[i].stuArr[j].score = 40 + rand() % 61;
		}
	}
}

// 7. 定义 打印信息的函数
void printInfo(Teacher tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "老师的姓名: " << tArray[i].tName << "\n" << "\n\t学生: ";
		for (int j = 0; j < 5; j++) {
			cout << "学生姓名: " << tArray[i].stuArr[j].sName << "学生分数" << tArray[i].stuArr[j].score << endl;
		}
		cout << endl;
	}
	return;
}