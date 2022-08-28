#include<iostream>


//using namespace std;
using std::string;
using std::cout;
using std::endl;

// 1.定义 英雄 结构体
struct Hero {
	string name;
	int age;
	string sex;
};


// 3. 声明录入信息的函数
void importInfo(Hero heroArr[], int length);
int main() {
	// 2. 创建英雄结构体 数组变量
	Hero heroArr[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};
	int len = sizeof(heroArr) / sizeof(heroArr[0]);
	importInfo(heroArr,len);
	system("pause");
	return 0;
}

// 4. 定义导入信息的函数, 进行冒泡排序
void importInfo(Hero heroArr[], int length) {
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = 0; j < length-i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age) {
				Hero temp = heroArr[j + 1];
				heroArr[j + 1] = heroArr[j];
				heroArr[j] = temp;
			}
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << "姓名: " << heroArr[i].name << "\t 年龄: " << heroArr[i].age << "\t性别: " << heroArr[i].sex << endl;
	}
}