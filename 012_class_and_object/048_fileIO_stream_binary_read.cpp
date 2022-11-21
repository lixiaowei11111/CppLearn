#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ifstream;


// 读取二进制文件 binary_file.txt
class Person {
public:
	char m_Name[64];
	int m_Age;
};


void test01() {
	// 1. 添加头文件
	// 2. 创建stream 对象
	ifstream ifs("binary_file.txt", ios::in | ios::binary);

	// 3. 判断是否读取成功
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	};

	// 4. 将文件类型 赋值给变量
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	cout << "年龄:" << p.m_Age << endl;
	cout << "名字:" << p.m_Name << endl;

	//5. 关闭 stream 对象
	ifs.close();
}
int main() {
	test01();
	system("pause");
	return 0;
}
