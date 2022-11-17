#include <iostream>
#include<fstream>
#include<sstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::getline;

// 读文件
void test01() {
	// 1.引入头文件
	//2. 创建 流 对象
	ifstream ifs;

	//3.打开文件
	ifs.open("fileIO_Demo.txt", ios::in);

	//3.1 判断文件是否打开失败
	if (!ifs.is_open() ){
		cout << "文件打开失败" << endl;
	}

	//4.读取文件数据的四种方式
	
	// 4.1 方式一 C风格的字符串 循环接收
	/*char buf[1024] = {};
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/

	//4.2 方式二 C风格的字符串, 配合 ifstream的getline函数, getline参数, 1.用来接收数据的字符串,2.输出的大小
	/*char buf[1024] = {};
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	//4.3 方式三 C++ 风格的字符串,接收数据, 全局函数getline 传递数据
	/*string str;
	while (getline(ifs,str))
	{
		cout << str << endl;
	}*/

	//4.4 方式四 单个字符接收, 使用 ifstream的 get函数进行单个字符赋值
	char c;
	while ((c = ifs.get())!=EOF) //EOF(end of file) 用来判断文件操作是否结束的标志
	{
		cout << c;
	}


	//5. 关闭文件
	ifs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}
