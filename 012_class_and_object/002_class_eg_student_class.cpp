#include<iostream>


using std::cout;
using std::endl;
using std::string;
using std::cin;

// 定义一个学生类, 有姓名和学号属性, 可以给姓名和学号赋值, 可以显示学生的学号
class Student {
	public:
		string s_name;
		string s_id;

		void setStuName(string name) {
			s_name = name;
		};
		void setStuId(string id) {
			s_id = id;
		};

		void showStuInfo() {
			string type = "";
			cout << "请输入需要查询的信息, name:学生姓名;id:学生学号;all:姓名和学号" << endl;
			cin >> type;
			if (type == "name") {
				cout << s_name << endl;
			}
			else if (type == "id") {
				cout << s_id << endl;
			}
			else if (type == "all") {
				cout <<"姓名" << s_name << endl;
				cout <<"学号" << s_id << endl;
			}
		};


};


int main2() {
	Student stu1;
	stu1.setStuName("张三");
	stu1.setStuId("114514");

	stu1.showStuInfo();

	system("pause");
	return 0;
}