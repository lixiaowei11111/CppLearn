#include <iostream>

using std::cout;
using std::endl;
using std::string;


//template<class T> // 定义泛型关键字 可以用 typename 也可以用 class
// 一般可以定义类class时 使用 class ,定义函数时使用 typename
// 或者 无论函数 还是 类 ,都用class 关键字
// 使用泛型时,要注意的两点

//1. 自动类型推导，必须推导出一致的数据类型T,才可以使用

template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void test01() {
	int a = 10;
	string b = "aa";
	char char1[] = "1311331";
	//mySwap(a, b);// error 没有与参数类型匹配的函数模板
	//mySwap(b, char1);// error 没有与参数类型匹配的函数模板
}

// 2. 模板必须要确定出T的数据类型，才可以使用
template<class T>
void func() {
	cout << "运行func函数" << endl;
}

void test02() {
	//func();//error 函数必须要确定出T的数据类型 才可以使用
	func<string>();// 运行func函数
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
