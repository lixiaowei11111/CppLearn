#include<iostream>

using namespace std;

int main2() {

	// 1.�ҳ�1ά������,�����Ǹ���
	const long array1[] = { 100,34,322,56,88,11 };

	int length = sizeof(array1) / sizeof(array1[2]);

	int maxNumber = 0;
	for (int i = 0; i <length ; i++)
	{	
		if (maxNumber < array1[i]) {
			maxNumber = array1[i];
		};
	}
	cout << "array1����Ԫ���е����ֵΪ:" << maxNumber << endl;


	// 2. ����� reserve ����
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