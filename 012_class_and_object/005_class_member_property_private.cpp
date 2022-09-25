#include<iostream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;


// 设置 class 中的 成员属性设为私有
// 1.可以控制成员属性的读写
// 2.对于写权限,可以检测数据的有效性

class Person {
public:
	void setName(string name) {
		p_name = name;
	};
	void getName() {
		cout << p_name << endl;
	};
	void getAge() {
		cout << (p_age ? 0 : p_age) << endl;
	};
	void setSex(int sex) {
		p_sex = sex == 1 ? "男" : "女";
	}



private:
	string p_name;// 可读可写
	int p_age;// 只读
	string p_sex;// 只写
};

int main5() {
	Person person;
	person.setName("张三");
	person.setSex(1);
	person.getAge();
	person.getName();
	system("pause");
	return 0;
}