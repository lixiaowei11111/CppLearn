#include<iostream>
using namespace std; // 预编译 命名空间为 std里面的函数



// 利用new创建一个变量
double* test01() {
	return new double(3.14159); // new 在堆区开辟数据
};

// 2.利用 new创建一个数组
void test02() {
	int* p = new int[10];// 中括号[]代表的是 数组, 表示这个数组有10个元素

	for (size_t i = 0; i < 10; i++)
	{
		p[i] = 100 + i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << p[i] << endl;// 100 101 102 103 104 105 106 107 108 109
	}

	delete[]  p;
};


int main() {
	double* p1 = test01();


	cout << *p1 << endl;// 3.14159
	// 堆区的数据不会被编译器自动释放,
	cout << *p1 << endl;//3.14159

	//使用delete 关键字释放 变量, 语法: delete 地址
	delete p1;

	//cout << *p1 << endl;// delete在堆区,编译器提示:拥有未初始化的内存p1

	test02();

	system("pause");
	return 0;
}