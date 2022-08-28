#include<iostream>

using namespace std;

int main1() {
	// 1.数组初始化定义 方式1
	double array1[10];

	//2. 数组的初始化 方式2
	double array2[] = { 1,2,3,4,5,6,7 };
	cout << "数组array占用1的内存空间未:" << sizeof(array2)<<"byte" << array2 << endl;

	// 3. 数组的初始化 方式3
	double array3[3] = { 1,2,3 };

	// 4. 获取字符串长度的方法 strlen(char)
	 char char1[] ="adadadsaddada";
	 cout << "use strlen function get string length is :" << strlen(char1);//13

	 // 5. 获取数组类型的方法
	 string array4[] = { "1","2","3","4" };
	 cout << "string 类型数组的占用内存空间大小为" << sizeof(array4) << "\n" << sizeof(string) << endl;


	 // 6. c++ 中计算数组的长度, 利用sizeof
	 for (int i = 0; i < sizeof(array4) / sizeof(array4[0]); i++) {
		 cout << array4[i]<<array4 << endl;
	 }


	 // 7. sizeof 获取 array在地址中长度
	 double array5[] = { 1,2,3,4,5,6,7 };
	 int a = sizeof(array5); // array5整个数组的长度
	 int b = sizeof(array5[0]); // 数组单个元素的长度,也可以用array5[1]来替代
	 int b1 = sizeof(array5[1]);
	 cout << "array5的数组长度为:" << (a / b) << endl;// 7
	 cout << "array5数组的长度为" << (a / b1) << endl;// 7

	system("pause");
	return 0;
}