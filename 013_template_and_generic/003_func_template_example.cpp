#include <iostream>

using std::cout;
using std::endl;
using std::string;

//	* ���ú���ģ���װһ������ĺ��������Զ�**��ͬ������������**��������
//	*�������Ӵ�С�������㷨Ϊ** ѡ������**
//	* �ֱ�����** char����** ��** int����** ���в���

// �������ͺ���
template<class T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
};
 //ѡ������, �Ӵ�С ��������
template<class T>
void myArrSort(T arr[],int len) {

	// ѡ�������㷨ʵ��
	for (int i = 0; i < len; i++) {
		// ����������±�Ϊ i
		int max = i;
		for (int j = i + 1; j < len; j++) {
			// ����Ƚ�,ֱ���ҵ���max�������
			if (arr[max] < arr[j]) {
				max = j;// ����ϴ�������±�
			}
		}
		if (max != i) {// ��� max������, �ͽ�����������λ��
			mySwap(arr[max], arr[i]);// ���˸��ֺ�Ϊʲô����ʾ
		}
	}
};
// �����ӡ
template<class T>
void printfArr(T arr[],int len) {
	//int len = sizeof(arr) / sizeof(T);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void test01() {
	// char����
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
