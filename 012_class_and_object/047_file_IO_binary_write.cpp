#include <iostream>
#include<fstream>


using std::cout;
using std::endl;
using std::ofstream;
using std::ios;


// 写入二进制文件
class Person {
public:
	char m_Name[64];
	int m_Age;
};


void test01() {
	// 1.包含头文件
	// 2.利用构造函数创建并初始化 stream 对象
	ofstream ofs("binary_file.txt", ios::out | ios::binary);

	// 3. 写入 类文件进入对象
	Person p = { "张三",28};//c++中 class 也可以使用 struct的创建方式, 注意class 和 struct的区别, 只在权限上有区别
	ofs.write((const char*) &p,sizeof(p));
	// (const char*)&ofs 的意思是将 Person* 强制转为 char* 指针;分为 两部分看 (const char*) 指的是要把一个类型强制转换为 char*型; &ofs 表示的是Person* 类型的指针

	// 4. 关闭 stream 对象
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}
