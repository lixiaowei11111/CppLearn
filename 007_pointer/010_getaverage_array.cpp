#include <iostream>

using namespace std;

double getAverage(int * arr, int size);

int main10()
{	
	int arr[5] = { 1,2,3,4,5 };
	int length = (sizeof(arr) / sizeof(arr[0]));
	double avg = getAverage(arr, length);
	cout << "平均数为:" << avg << endl;
	return 0;
}

// 求参数一数组的平均值
double getAverage(int* arr, int size) {
	int total = 0;
	double avg = 0;
	for (int i = 0; i < size; i++)
	{
		total = total + arr[i];
	}
	cout << "总数为:" << total << endl;
	avg = double(total) / size;
	return avg;
}