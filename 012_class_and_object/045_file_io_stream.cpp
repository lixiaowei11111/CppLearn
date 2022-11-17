#include <iostream>
#include<fstream>


using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ios;
// 写文本文件
// **文本文件** -文件以文本的 **ASCII**形式存储在计算机中
//操作文件的三大类:
//
//1. ofstream : 写操作
//2. ifstream : 读操作
//3. fstream : 读写操作

// 写文件步骤
void test01() {
	// 1. 引入 fstream 头文件
	// 2. 创建 流 对象
	ofstream ofs;
	// 3.打开文件方式
	ofs.open("fileIO_Demo.txt", ios::out);
	// 4.写数据
	ofs << "这是一条被写入的数据" << endl;
	ofs << "这是txt文本" << endl;
	// 5. 关闭文件
	ofs.close();

}

void test02() {
	// 1. 引入 fstream 头文件
	// 2. 创建 流 对象
	ofstream ofs;
	// 3.打开文件方式
	ofs.open("./fileIO/01.txt", ios::out);
	// 4.写数据
	ofs << "这是一条被写入的数据" << endl;
	ofs << "这是txt文本" << endl;
	// 5. 关闭文件
	ofs.close();

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
