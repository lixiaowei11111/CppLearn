#include <iostream>

using std::cout;
using std::endl;
using std::string;

//	* 利用函数模板封装一个排序的函数，可以对**不同数据类型数组**进行排序
//	*排序规则从大到小，排序算法为** 选择排序**
//	* 分别利用** char数组** 和** int数组** 进行测试

// 交换泛型函数
template<class T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
};
 //选择排序, 从大到小 依次排序
template<class T>
void myArrSort(T arr[],int len) {

	// 选择排序算法实现
	for (int i = 0; i < len; i++) {
		// 假设最大数下表为 i
		int max = i;
		for (int j = i + 1; j < len; j++) {
			// 逐个比较,直到找到比max还大的数
			if (arr[max] < arr[j]) {
				max = j;// 保存较大的数的下标
			}
		}
		if (max != i) {// 如果 max被改了, 就交换两个数的位置
			mySwap(arr[max], arr[i]);// 少了个分号为什么不提示
		}
	}
};
// 逐个打印
template<class T>
void printfArr(T arr[],int len) {
	//int len = sizeof(arr) / sizeof(T);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01() {
	// char数组
	char a[] = "abcdefg";
	int len = sizeof(a) / sizeof(char);
	myArrSort(a, len);
	printfArr(a,len);
}


int main() {
	test01();
	system("pause");
	return 0;
}
