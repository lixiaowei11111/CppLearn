#include<iostream>

using namespace std;

int main2() {

	// 1.找出1维数组中,最大的那个数
	const long array1[] = { 100,34,322,56,88,11 };

	int length = sizeof(array1) / sizeof(array1[2]);

	int maxNumber = 0;
	for (int i = 0; i <length ; i++)
	{	
		if (maxNumber < array1[i]) {
			maxNumber = array1[i];
		};
	}
	cout << "array1数组元素中的最大值为:" << maxNumber << endl;


	// 2. 数组的 reserve 方法
	const double array2[] = { 1,3,5,7,9,10 }; 
	int length2 = sizeof(array2) / sizeof(array2[0]);
	double array3[6];

	for (int i = 0; i < length2; i++)
	{
		for (int c = length2-1; c >0; c--)
		{
			array3[i] = array2[c];
		}
	}
	for (size_t i = 0; i < length2; i++)
	{
		cout << array3[i] << endl;
	}


	system("pause");
	return 0;
}