#include <iostream>

using namespace std;


// 1. 定义一个返回 数组的函数(c++ 不能直接返回数组,但是可以返回地址)
int* bubbleSort(int* arr,int size);

int main()
{
	int arr[] = { 2,6,3,8,1,4,9 };
	int length = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr,length);
	for (int i = 0; i < length; i++)
	{
		/*cout << bubbleSort(arr, length)[i] << " ";*/
		cout << arr[i] << " ";
	}
	return 0;
}


int* bubbleSort(int* arr,int size) {
	cout<<sizeof(arr)/sizeof(arr->*[0])<<endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}