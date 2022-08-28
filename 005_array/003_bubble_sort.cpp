#include<iostream>

using namespace std;

int main3() {

	// 1. ≈≈–Ú«∞
	int array1[] = { 3,5,1,0,3,4,7,6,9 };
	int length = sizeof(array1) / sizeof(array1[0]);
	for (size_t i = 0; i < length; i++)
	{
		cout << array1[i] << " ";
	}cout << endl;

	// 2.√∞≈›≈≈–Ú
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i - 1; j++) {
			if (array1[j] > array1[j + 1]) {
				int temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
			}
		}
	}

	//3.≈≈–Ú∫Û
	for (size_t i = 0; i < length; i++)
	{
		cout << array1[i] << " ";
	}cout << endl;


	system("pause");
	return 0;
}